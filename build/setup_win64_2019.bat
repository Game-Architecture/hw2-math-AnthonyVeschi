@echo off

mkdir ga1-win64
cd ga1-win64
cmake -G "Visual Studio 16 2019" ../../src/engine
cd ..
