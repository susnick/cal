@echo off
WHERE gcc>nul 2>nul
IF %ERRORLEVEL% NEQ 0 goto runcl

gcc cal.c -ocal
goto finish



:runcl
cl cal.c
rm cal.obj


:finish
move cal.exe %CMDER_ROOT%\bin
