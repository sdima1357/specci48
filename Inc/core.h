#ifndef TEST1_ILI9341_CORE_H
#define TEST1_ILI9341_CORE_H

//~ #include <stm32f10x.h>
//~ #include <stm32f10x_spi.h>

#define LCD_setAddressWindowToWrite(x1,y1,x2,y2) \
    LCD_setAddressWindow(x1, y1, x2, y2); \
    dmaSendCmd(LCD_GRAM)

#define LCD_setAddressWindowToRead(x1,y1,x2,y2) \
    LCD_setAddressWindow(x1, y1, x2, y2); \
    dmaSendCmd(LCD_RAMRD)

uint16_t LCD_getWidth();
uint16_t LCD_getHeight();

void LCD_init();
void LCD_idle(uint32_t mode) ;
void LCD_setSpi8(void);
void LCD_setSpi16(void);
void LCD_readSometing(uint8_t * buffr,uint8_t command,int commandLen);
uint32_t LCD_ReadID(uint8_t command,int commandLen);
void LCD_setOrientation(uint8_t o);
void LCD_setAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_fillRect(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t color);
void LCD_fillRect2(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t color,uint16_t seccolor);
void LCD_FullRect6(uint16_t x1, uint16_t y1,uint8_t * adress,uint8_t * adress1,uint16_t w,uint16_t h);
void LCD_Draw_Text(const char* Text, int16_t X, int16_t Y, uint16_t Colour, uint16_t Size, uint16_t Background_Colour);
//~ void LCD_WriteWord(uint16_t x1, uint16_t y1, uint32_t color) ;
//~ uint32_t LCD_ReadWord(uint16_t x1, uint16_t y1) ;
void  LCD_Read64bytes(uint16_t x1, uint16_t y1,uint8_t * adress) ;
void  LCD_Write64bytes(uint16_t x1, uint16_t y1,uint8_t * adress) ;
void LCD_Write8line(uint16_t x1, uint16_t y1,uint8_t * adress) ;
void LCD_Write4line(uint16_t x1, uint16_t y1,uint8_t * adress) ;

#endif //TEST1_ILI9341_CORE_H
