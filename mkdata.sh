#!/bin/bash

if [ -a data.txt ]
then
    echo "Detected data file, deleting"
    rm -r data.txt
fi

for ((a=1; a <= 1000000 ; a++))
do
    rnumber=$((RANDOM%1000000000+1))
    echo $rnumber >> data.txt
done