@echo off

rem netsh wlan show networks

rem - Network Sharing Center - Set up new connection - manual - Enter SSID

rem netsh interface ip set address name="WiFi" source=static addr=192.168.2.10 mask=255.255.255.0

netsh wlan set profileparameter GSAH connectiontype=ibss connectionmode=manual

netsh wlan connect GSAH

rem netsh wlan disconnect

rem netsh wlan delete profile name = GSAH
