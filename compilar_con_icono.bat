@echo off
set GCC_PATH=c:\Users\elvis.rodriguez\Downloads\winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64msvcrt-14.0.0-r7\mingw64\bin
"%GCC_PATH%\windres.exe" resources.rc -o resources.o
"%GCC_PATH%\gcc.exe" Principal.c resources.o -o andrea.exe -static -lm
echo Compilacion completada con exito (andrea.exe).
pause