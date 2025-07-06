#!/bin/bash

> log.txt
for line in {1..2}
do
    echo "2 números línea=$line" >> log.txt
    value=$(./push_swap $(awk -v num="$line" 'NR==num {gsub(/"/, ""); print}' tests.txt) | wc -l| xargs)
    if [ "$value" -gt 1 ]; then
        echo "KO $value" >> log.txt
    else
        echo "OK $value" >> log.txt
    fi
done

for line in {4..9}
do
    echo "3 números línea=$line" >> log.txt
    value=$(./push_swap $(awk -v num="$line" 'NR==num {gsub(/"/, ""); print}' tests.txt) | wc -l| xargs)
    if [ "$value" -gt 4 ]; then
        echo "KO $value" >> log.txt
    else
        echo "OK $value" >> log.txt
    fi
done

for line in {11..34}
do
    echo "4 números línea=$line" >> log.txt
    value=$(./push_swap $(awk -v num="$line" 'NR==num {gsub(/"/, ""); print}' tests.txt) | wc -l| xargs)
    if [ "$value" -gt 7 ]; then
        echo "KO $value" >> log.txt
    else
        echo "OK $value" >> log.txt
    fi
done

# for line in {34..153}
# do
#     echo "5 números línea=$line"  >> log.txt
#     value=$(./push_swap $(awk -v num="$line" 'NR==num {gsub(/"/, ""); print}' tests.txt) | wc -l| xargs)
#     if [ "$value" -gt 1 ]; then
#         echo "KO $value" >> log.txt
#     else
#         echo "OK $value" >> log.txt
#     fi
# done

awk 'prev ~ /números línea/ && /KO/ {print prev "; comb = " $2} {prev=$0}' log.txt

