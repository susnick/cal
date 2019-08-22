@echo off

REM :runcl
REM WHERE cl>nul 2>nul
REM IF %ERRORLEVEL% NEQ 0 goto rungcc
REM cl cal.c
REM rm cal.obj
REM goto finish

:rungcc
::WHERE gcc>nul 2>nul
::IF %ERRORLEVEL% NEQ 0 goto downloadtools
%cd%\gcc cal.c -ocal
goto finish

:downloadtools
echo You do not have any of the required build tools installed.
echo Downloading build tools now.
::powershell -Command "Invoke-WebRequest https://bitbucket.org/susnick/cal/downloads/mingw64.zip -OutFile mingw64.zip"
bitsadmin /transfer downloadjob /dynamic /priority foreground https://bitbucket.org/susnick/cal/downloads/mingw64.zip %cd%\mingw64.zip

powershell Expand-Archive mingw64.zip
rm mingw64.zip
set PATH=%cd%\mingw64\bin;%PATH%
goto rungcc

:finish
IF NOT EXIST %cd%\bin\NUL GOTO NOWINDIR
goto movefile


:NOWINDIR
mkdir bin

:movefile
move cal.exe %cd%\bin