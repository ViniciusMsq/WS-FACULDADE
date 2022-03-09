@echo off
chcp 65001
title Exercicio DOS
echo limpando o desktop
pause
c:
cd\
md bk
cd\Users\%username%\Desktop
move * c:\bk
pause
