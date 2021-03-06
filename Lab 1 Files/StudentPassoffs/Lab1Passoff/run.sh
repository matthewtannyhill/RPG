#!/bin/bash

# Pass Off Script
# author: Matt Hoiland
# last edit: 2017-01-19

EXE="program"
VERSION="-std=c++14"
FLAGS="-g -Wall"

MAIN="lab1_main.cpp"
cp ArenaInterface.h src
cp FighterInterface.h src

if [[ -e $MAIN ]];
then
    cp $MAIN src/
else
    echo "TA main file is missing. Cannot proceed"
    exit 1
fi

if g++ $VERSION $FLAGS src/*.cpp src/*.h -o tests/$EXE;
then
    echo "Compilation succeeded!"
else
    echo "Compilation failed."
    exit 1
fi

cd tests
echo ""
echo "Moved to $(pwd)"

echo ""
echo "Running Student Program"
echo "--------"
valgrind --leak-check=full --show-leak-kinds=all ./$EXE
rm $EXE
mv out_file*.txt ../output
echo "--------"

cd ../
echo ""
echo "Moved to $(pwd)"

echo ""
echo "Running Diff"
echo "--------"
for f in tests/file*.txt;
do
    f=${f#tests/}
    sdiff -s keys/key_$f output/out_$f > diffs/diff_$f
    if [ ${PIPESTATUS[0]} -eq 0 ];
    then
        echo "key_$f and out_$f are identical"
    else
        echo "key_$f and out_$f differ :: check diffs/diff_$f for details"
    fi
done
echo "--------"

