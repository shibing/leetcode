#!/bin/bash
awk '
    {
        for (i = 1; i <= NF; ++i)
            numberMap[$i]++
    }
    END {
        for (key in numberMap) {
            print key " " numberMap[key]
        }
    }
' words.txt | sort -nr -k 2
