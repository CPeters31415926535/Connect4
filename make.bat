CALL :compile
SET toRun=run
:while
if not "%toRun%" == "exit" (
 CALL :%toRun%
 set toRun=exit
 set /P toRun=""
 goto :while
)

:compile
g++ -std=c++17 *.cpp
EXIT /B 0

:run
a
EXIT /B 0

pause