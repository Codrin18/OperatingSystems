#!/bin/bash

folder=$1
tmpfile=$(mktemp)
tmpfile2=$(mktemp)


find $folder -printf "%f\n" | uniq -c > ${tmpfile}
sed -i 's/^ *//' ${tmpfile} #delete the space in front of the first word of every line
cut -f 2- -d ' ' ${tmpfile} > ${tmpfile2}
sort ${tmpfile2} | uniq --count
