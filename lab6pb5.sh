

find $2 -type f -exec sh -c 'file="{}"; mv "$file" "${file}.unu"' \;
mv $2 $1
