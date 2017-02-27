@echo off  			
@echo this program is to get the ARM address automatic	
@echo author wang.bin						
@echo date:2016.06.12							

@echo 当前目录是：%cd%  
@set currpath=%cd%  

@set PrjPath=%1

@set IarInstallPath=%2

copy /y .\GetAddress.c %PrjPath%
::/y means copy and replace the same name file

cd /d %IarInstallPath%
::go into  iar directory

IarBuild.exe %PrjPath%\GetAddr.ewp -build Debug
::build (optional -log all)

cd /d %PrjPath%\settings
::go into settings

start GetAddr.Debug.cspy.bat
::start cspy debug ,this file is in the settings directory,we need use the IDE to bulid this file at first time

ping 127.1 -n 15 >nul
::delay 15s

cd /d %IarInstallPath%
::go into the directory

taskkill /f /t /im CSpyBat.exe
::kill cspybat

cd /d %currpath%
::go into current path

copy /y %PrjPath%\settings\Addr.txt  .\
::copy addr.txt

taskkill /f /t /im cmd.exe
::kill the cspy opened cmd.exe