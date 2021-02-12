@echo off

mkdir ga2-win64
cd ga2-win64
cmake -G "Visual Studio 15 2017 Win64" ../../src/engine
cd ..
