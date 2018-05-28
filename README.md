stm32f103c8t6  spectrum48  emulator
Work in progress... Right now only proof of concept
https://youtu.be/n4u6VNxCTdA

today i have recieved new blue pill board .
Seems that not every board the same , part of them 64K 
Older board (same price) was have 128K flash 

On ili9341 board You must close(short) jumper J1 to 3.3v .Check board documentation... 5 volt can damage your stm32
Touch,Display and SD card use common (3 wire CLK,MISO,MOSI) SPI1 interface. Chip selects are different.
