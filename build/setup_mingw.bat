@echo off

mkdir ga2-win64
cd ga2-win64
cmake -G "MinGW Makefiles" -DVIDEO_OPENGLES=0 ../../src/engine
cd ..
