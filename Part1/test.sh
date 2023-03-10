#!/bin/bash

g++ 17.*
for number in 1 2 3 4 9 16 25 30 36 40 49
do
    ./a.out <<<"$number"
done
