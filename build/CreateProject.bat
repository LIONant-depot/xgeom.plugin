rmdir /s /q xgeom_compiler.vs2022
rem rmdir /s /q ..\dependencies
cmake ../ -G "Visual Studio 17 2022" -A x64 -B xgeom_compiler.vs2022
pause