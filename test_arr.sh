#!/bin/bash

echo "Testing "$@""
for i in "$@"
do
    echo "Testing: "${i}""
    for ((a=50000; a <= 1000000 ; a += 50000))
    do
        echo "$a"
        ./${i} "$a"
    done 
done
