#!bin/bash
# You can download Dawg Print Drivers at http://f2.washington.edu/fm/c2/printing-copying/dawg-prints-printer-locations
# Put this script in the directory where you download all your compressed printer driver files (.tar)
# Good Read about bash string: http://www.gnu.org/software/bash/manual/html_node/Shell-Parameter-Expansion.html#Shell-Parameter-Expansion

echo

FILE_PATTERN="*.tar"
FILE_FILTER=$(find . -name "$FILE_PATTERN")

for file in $FILE_FILTER
do
    echo "$file is going to be extracted"
    tar -xvf $file
    echo "$file has been extracted"

    filename=$(basename "$file") # Full filename with extension
    extension="${filename##*.}"
    filename="${filename%.*}" # No extension
    
    cd $filename
    bash *.sh
    cd ..
done
