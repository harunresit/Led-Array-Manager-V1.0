#!/bin/bash


MOUSE_ID=$(xinput --list | grep -i -m 1 'Mouse        	id=10' | grep -o 'id=[0-9]\+' | grep -o '[0-9]\+')


STATE1=$(xinput --query-state $MOUSE_ID | grep 'button\[' | sort)
while true; do
    STATE2=$(xinput --query-state $MOUSE_ID | grep 'button\[' | sort)
    #comm -13 <(echo "$STATE1") <(echo "$STATE2")

    if [ "$STATE1" != "$STATE2" ]; then
        output=$(xdotool getmouselocation)
        x=$(echo $output | awk '{print $1}' | cut -d":" -f2)
        y=$(echo $output | awk '{print $2}' | cut -d":" -f2)

        echo "X= $x" >> positions.txt
        echo "Y= $y" >> positions.txt
    fi

    STATE1=$STATE2
done