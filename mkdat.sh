#!/bin/bash

rm -r dig.txt

for ((a=1; a <= 1000000 ; a++))
do
    rnumber=$((RANDOM%1000000000+1))
    echo $rnumber >> dig.txt
done