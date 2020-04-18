#!/bin/bash


#Să se afișeze pentru fiecare fișier: numele acestuia, și 
#numărul mediu de cuvinte per linie per fișier (media numărului de cuvinte pentru liniile fișierului). Se va afișa și media numărului de cuvinte pentru toate fișierele luate la un loc.
n=0;
for file in "$@"
do
	f=$(awk 'END{print FILENAME}' $file);
	t=$( awk '{ n += NF }END{ print int(n/NR)}' $file);
	n=$(($n+$t));
	printf "\n$f" 
	printf "\n$t" 
done

printf "\n$(($n/$#))"