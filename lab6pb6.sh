

folder=$1

for file in "$folder"/*
do
  echo $file
  NAME=`echo "$file" | cut -d'.' -f1`
  set -- $NAME*
  echo "$#"
done
