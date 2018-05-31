Project name: specci48

Description:   Sinclair ZX spectrum48 emulator on stm32f103c8t6 & ILI9341 SPI display
  
Installation on ubuntu:
>git clone https://github.com/sdima1357/specci48
>cd specci48
>make 
.. connect hardware
>./load.sh

Status:

Work in progress... Right now only proof of concept
https://youtu.be/n4u6VNxCTdA

today i have recieved new blue pill board .
Seems that not every board the same , part of them 64K 
Older board (same price) was have 128K flash 

On ili9341 board You must close(short) jumper J1 to 3.3v .Check board documentation... 5 volt can damage your stm32
Touch,Display and SD card use common (3 wire CLK,MISO,MOSI) SPI1 interface. Chip selects are different.

Credits:
1. Sir Clive Marles Sinclair
1. started from here: 
gorien for stm32f4 (last version very simular to fuse,same macros)
http://forum.easyelectronics.ru/viewtopic.php?f=35&t=16592&start=150

1. most tricks from here, but simplified & reduced and added partially instruction decoding: 
fuse (http://fuse-emulator.sourceforge.net/)

1. baseline display routines from: 
fagcinsk (https://github.com/fagcinsk/stm-ILI9341-spi/)

1. touch from here,completely rewritten calibration by LS 6 points: 
martnak (https://github.com/martnak/STM32-ILI9341)

1. stm32 libraries from st (http://www.st.com/content/st_com/en.html)
