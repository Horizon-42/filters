echo off
cd ./build || exit
cmake -G .. > TriffleInfo
make