#!/bin/bash
TARGET_FILE="/tmp/target_kbd"

for dir in by-path by-id; do
    if [ -d "/dev/input/$dir" ]; then
        for link in /dev/input/$dir/*-event-kbd /dev/input/$dir/*-kbd; do
            if [ -L "$link" ] && [ -e "$link" ]; then
                target=$(readlink -f "$link")
                echo "keyboard found ($dir): $target"
                echo "$target" > "$TARGET_FILE"
                exit 0
            fi
        done
    fi
done

echo "no keyboard found"
exit 1

