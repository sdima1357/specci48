stm32f103c8t6  spectrum48  emulator
Work in progress... Right now only proof of concept
https://youtu.be/n4u6VNxCTdA

today i have recieved new blue pill board .
Seems that not every board the same , part of them 64K and maximum freq 72MHz and max pll multplier must be change to RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9; 

Older board (same price) has  128K flash and 112MHz and RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL14;
Anyway if it not works,try to reduce PLL freq.

