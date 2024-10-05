#!/bin/bash

# Change this depending on what device you're generating the screenshots on
fb_res=1920x1080

executable=$1
outdir=screenshots
config=buffyboard-screenshots.conf

root=$(git rev-parse --show-toplevel)
themes_c=$root/shared/themes.c

resolutions=(
    # Nokia N900
    480x800
    800x480
    # Samsung Galaxy A3 2015
    540x960
    960x540
    # Samsung Galaxy Tab A 8.0 2015
    768x1024
    1024x768
    # Pine64 PineTab (landscape)
    1280x800
    # Pine64 PinePhone (landscape)
    1440x720
    # BQ Aquaris X Pro (landscape)
    1920x1080
)

if ! which fbcat > /dev/null 2>&1; then
    echo "Error: Could not find fbcat" 1>&2
    exit 1
fi

if [[ ! -f $executable || ! -x $executable ]]; then
    echo "Error: Could not find executable at $executable" 1>&2
    exit 1
fi

function write_config() {
    cat << EOF > $config
[theme]
default=$1

[input]
pointer=false
touchscreen=false
EOF
}

function clean_up() {
    rm -f $config
}

trap clean_up EXIT

rm -rf "$outdir"
mkdir "$outdir"

readme="# Buffyboard themes"$'\n'

clear # Blank the screen

while read -r theme; do
    write_config $theme

    readme="$readme"$'\n'"## $theme"$'\n\n'
    
    for res in ${resolutions[@]}; do
        $executable -g $res -C $config > /dev/null 2>&1 &
        pid=$!

        sleep 3 # Wait for UI to render

        fbcat /dev/fb0 > "$outdir/$theme-$res.ppm"
        kill -15 $pid

        convert \
            -size $fb_res \
            $outdir/$theme-$res.ppm \
            screenshot-background.png \
            -crop $res+0+0 \
            -gravity NorthWest \
            -composite \
            "$outdir/$theme-$res.png"

        rm "$outdir/$theme-$res.ppm"

        readme="$readme<img src=\"$theme-$res.png\" alt=\"$res\" height=\"300\"/>"$'\n'

        sleep 1 # Delay to prevent terminal mode set / reset interference
    done
done < <(grep "name =" "$themes_c" | grep -o '".*"' | tr -d '"' | sort)

echo -n "$readme" > "$outdir/README.md"
