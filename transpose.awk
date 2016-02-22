    BEGIN {
        rows = 1
    }
    {
        for(i = 1; i <= NF; ++i ) {
            lines[rows][i] = $i
        }
        rows++
        colums = NF
    }
    END {
        rows--
        for(i = 1; i <= colums; ++i) {
            line = ""
            for (j = 1; j <= rows; ++j) {
                if (j == 1) {
                    line = lines[j][i]
                } else {
                     line = line " " lines[j][i]
                }
            }
            print line
        }
    }
