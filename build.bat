@echo off
mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\Project/code/Main.cpp user32.lib Gdi32.lib Xinput9_1_0.lib
popd
PAUSE
