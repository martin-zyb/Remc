@echo off

call vendor\bin\premake\premake5.exe vs2022

if %errorlevel% NEQ 0 (
  pause
)