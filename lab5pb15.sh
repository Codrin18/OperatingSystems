#!/bin/bash

#Să se afișeze pentru fiecare fișier din linia de comandă raportul dintre numărul de vocale și numărul de consoane.


for file in "$@"
do
  vowels=$(awk '{print gsub(/[aeiou]/,"",$0)}' RS='^$'  $file)
  consonants=$(awk '{print gsub(/[bcdfghjklmnpqrstvwxyz]/,"",$0)}' RS='^$'  $file)
  printf "\n($vowels/$consonants)"

done
