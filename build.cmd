@echo off
WHERE gcc>nul 2>nul
IF %ERRORLEVEL% NEQ 0 goto runcl

gcc cal.c -ocal
goto finish



:runcl
cl cal.c
rm cal.obj


:finish
IF NOT EXIST %cd%\bin\NUL GOTO NOWINDIR
goto movefile


:NOWINDIR
mkdir bin

:movefile
move cal.exe %cd%\bin