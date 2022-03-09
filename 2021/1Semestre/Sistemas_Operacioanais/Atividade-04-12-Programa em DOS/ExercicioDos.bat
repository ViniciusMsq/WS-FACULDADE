@echo off
chcp 65001
title Exercicio DOS

goto header

:header
cls
echo *Programa em bat: Menu para visualizar informações de jogos.
echo *Vinicius "&" Alexandre
echo.
goto menu

:menu
echo    -Lista de Jogos-
echo.
echo [1] - Resident Evil 4
echo [2] - Fifa 21
echo [3] - God of War(2018)
echo [4] - Finalizar sistema
echo.
set /p opcao=Digite a opção desejada:

if "%opcao%" == "1" goto op1
if "%opcao%" == "2" goto op2
if "%opcao%" == "3" goto op3
if "%opcao%" == "4" goto op4
if "%opcao%" NEQ "1" echo Número invalido
pause
goto header
		
:op1  
echo iniciando pagina sobre Resident evil 4
start https://pt.wikipedia.org/wiki/Resident_Evil_4
goto fim

:op2  
echo iniciando pagina sobre Fifa 21
start https://pt.wikipedia.org/wiki/FIFA_21
goto fim

:op3  
echo iniciando pagina sobre God of war(2018)
start https://pt.wikipedia.org/wiki/God_of_War_(jogo_eletrônico_de_2018)
goto fim   

:op4
exit

:fim
echo.
echo Pagina acessada.
echo.
pause
goto header
