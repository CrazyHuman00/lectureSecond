#!/bin/sh
# cc -Wall -o magic magic.c などとしてコンパイルした（実行形式ファイルが magic ）場合、
#   $ bash msq_check.sh ./magic 
# として実行する

echo ========================= $1

echo "##### Magic #####"
echo "8 3 4 1 5 9 6 7 2" | $1
echo
echo "##### NotMagic #####"
echo 5 3 7 1 8 6 9 4 2 | $1
echo 6 5 7 1 9 8 2 4 3 | $1
echo 9 2 7 1 3 5 8 4 6 | $1
echo 9 7 8 1 2 3 5 6 4 | $1
echo 6 4 5 7 8 9 2 3 1 | $1
echo 9 4 2 7 5 3 8 6 1 | $1
echo 7 6 8 5 4 3 9 2 1 | $1

echo
