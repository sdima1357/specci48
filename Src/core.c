#include "stm32f1xx_hal.h"
#include "main.h"
#include "core.h"
#include "commands.h"
 void MX_SPI1_Init(int);
//~ #define  CHECK_SUMM
#define TFT_DC_SET        TFT_DC_GPIO_Port->BSRR = TFT_DC_Pin;
#define TFT_DC_RESET    TFT_DC_GPIO_Port->BSRR = (uint32_t)TFT_DC_Pin<<16U;


//~ #define TFT_RST_SET     GPIO_SetBits(GPIOA, TFT_RESET_PIN);
//~ #define TFT_RST_RESET   GPIO_ResetBits(GPIOA, TFT_RESET_PIN);

#define TFT_RST_SET        TFT_RESET_GPIO_Port->BSRR = TFT_RESET_Pin;
#define TFT_RST_RESET    TFT_RESET_GPIO_Port->BSRR = (uint32_t)TFT_RESET_Pin<<16U;

//~ #define TFT_CS_SET      GPIO_SetBits(GPIOA, TFT_CS_PIN);
//~ #define TFT_CS_RESET    GPIO_ResetBits(GPIOA, TFT_CS_PIN);

#define TFT_CS_SET        TFT_CS_GPIO_Port->BSRR = TFT_CS_Pin;
#define TFT_CS_RESET    TFT_CS_GPIO_Port->BSRR = (uint32_t)TFT_CS_Pin<<16U;


#define TFT_LED_SET        TFT_LED_GPIO_Port->BSRR = TFT_LED_Pin;
#define TFT_LED_RESET    TFT_LED_GPIO_Port->BSRR = (uint32_t)TFT_LED_Pin<<16U;

extern SPI_HandleTypeDef hspi1;
void SPIx_WriteReadData1(const uint8_t *DataOut, uint8_t *DataIn, uint16_t DataLength);
#define COLOR_3BYTES 1
static uint16_t screen_width  = LCD_PIXEL_WIDTH,
    screen_height = LCD_PIXEL_HEIGHT;

void SPIx_WriteF(uint8_t  Value)
{
	    while(((hspi1.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
	    {
		    //~ busy_counter++;
	    }  
	    *((__IO uint8_t*)&hspi1.Instance->DR) = Value;
}
void SPIx_ReadF(uint8_t * Value)
{
	    while(((hspi1.Instance->SR) & SPI_FLAG_RXNE) != SPI_FLAG_RXNE)
	    {
		    //~ busy_counter++;
	    }  
	    *Value =  *((__IO uint8_t*)&hspi1.Instance->DR);
}
    
#define SpixTimeout 50
//<editor-fold desc="Init commands">
//~ int flagReinit = 0;
static const uint8_t init_commands[] = {
        // Power control A
        6, LCD_POWERA, 0x39, 0x2C, 0x00, 0x34, 0x02,
        // Power control B
        4, LCD_POWERB, 0x00, 0xC1, 0x30,
        // Driver timing control A
        4, LCD_DTCA, 0x85, 0x00, 0x78,
        // Driver timing control B
        3, LCD_DTCB, 0x00, 0x00,
        // Power on sequence control
        5, LCD_POWER_SEQ, 0x64, 0x03, 0x12, 0x81,
        // Pump ratio control
        2, LCD_PRC, 0x20,
        // Power control 1
        2, LCD_POWER1, 0x10,
        // Power control 2
        2, LCD_POWER2, 0x10,
        // VCOM control 1
        3, LCD_VCOM1, 0x3E, 0x28,
        // VCOM cotnrol 2
        2, LCD_VCOM2, 0x86,
        // Memory access control
        2, LCD_MAC, 0x48,
	//~ 2, LCD_MAC, 0xC8,
        // Pixel format set
#ifdef COLOR_3BYTES
	2, LCD_PIXEL_FORMAT, 0x66,
#else
        2, LCD_PIXEL_FORMAT, 0x55,
#endif	
        // Frame rate control
        //3, LCD_FRMCTR1, 0x00, 0x1B,
	3, LCD_FRMCTR1, 0x00, 50,
        // Display function control
        4, LCD_DFC, 0x08, 0x82, 0x27,
        // 3Gamma function disable
        2, LCD_3GAMMA_EN, 0x00,
        // Gamma curve selected
        2, LCD_GAMMA, 0x01,
        // Set positive gamma
        16, LCD_PGAMMA, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
        16, LCD_NGAMMA, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
        0
};

/**
  * @brief  SPI error treatment function
  */
//~ #pragma GCC push_options
//~ #pragma GCC optimize ("Os")
//~ uint32_t busy_counter = 0;
//<editor-fold desc="LCD initialization functions">
#ifdef CHECK_SUMM
int32_t checkerror = 0;
int32_t checkdeinit = 0;
#endif
void dmaSendCmdCont(uint8_t cmd)
{
	uint8_t dummy;
	TFT_CS_RESET;
        TFT_DC_RESET;
	//~ HAL_StatusTypeDef status = HAL_OK;
	//~ status = HAL_SPI_TransmitReceive(&hspi1, (uint8_t*) &cmd,&dummy, 1, SpixTimeout);
	 /* Check the communication status */
	  //~ if(status != HAL_OK)
	  //~ {
	    /* Execute user timeout callback */
	    //~ SPIx_Error1();
	  //~ }	
    //~ while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
   //~ {
    //~ } 
	//~ *((__IO uint8_t*)&hspi1.Instance->DR) = cmd;
	//~ if(flagReinit)
	//~ {
	    int 	busy_counter=200;
	    while((((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)&&(busy_counter>0))
	    {
		   busy_counter--;
	    } 
	    while((((hspi1.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)&&(busy_counter>0))
	    {
		    busy_counter--;
	    }  
	    if(busy_counter>0)
	    {
		*((__IO uint8_t*)&hspi1.Instance->DR) = cmd;    
	    }
	    while(((hspi1.Instance->SR) & SPI_FLAG_RXNE) != SPI_FLAG_RXNE&&(busy_counter>0))
	    {
		    busy_counter--;
	    }  
	    if(busy_counter>0)
	    {
		dummy =  *((__IO uint8_t*)&hspi1.Instance->DR);
	    }
	    else
	    {
		SPIx_WriteReadData1(&cmd,&dummy,1);
		HAL_SPI_DeInit(&hspi1);	
		MX_SPI1_Init(0);
		SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
#ifdef CHECK_SUMM		    
		checkdeinit++;
#endif		    
	    }
/*
	    if( busy_counter==0)
	    {	    
		    
	    }
	    else
	    {
		
		    
		//~ SPIx_ReadF(&dummy);
	    }		    
		SPIx_WriteReadData1(&cmd,&dummy,1);
	
		//~ flagReinit =0;
	//~ }		
	//~ else
	//~ {
		//~ SPIx_WriteF(cmd);
		//~ SPIx_ReadF(&dummy);
		//~ while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
		//~ {
		//~ }
	//~ }	
	*/
}

void dmaSendDataCont8(uint8_t *data, uint32_t n) {
    //~ TFT_CS_RESET;
    TFT_DC_SET;
	int k;
	uint8_t dummy;
    for( k=0;k<n;k++)
    {
	    SPIx_WriteF(*(data));
	    data++;
    }
	    SPIx_ReadF(&dummy);
    while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
   {
    } 
    
}

#ifdef    COLOR_3BYTES
void color_convert(uint16_t color,uint8_t* result)
{
	//~ #define RED             0xF800 
	//~ #define BLUE            0x001F
	//~ #define GREEN           0x07E0  
	result[2]=  ((color&0x1f)		<<(1+2))<<1;//|0x80;    //5 bit BLUE
	result[1]=  (((color>>5)&0x3f) <<(0+1))<<1;//|0x80;    //6 bit GREEN 
	result[0]=  (((color>>11)&0x1f)<<(1+2))<<1;//|0x80;    //5 bit  //RED
}
#endif

void dmaSendDataCont16(uint16_t *data, uint32_t n) 
{
    int k;
    //~ TFT_CS_RESET;
    TFT_DC_SET;
    uint8_t dummy;
    uint8_t *pdata = (uint8_t *)data;
    for( k=0;k<n;k++)
    {
	    SPIx_WriteF(*(pdata+1));
	    SPIx_WriteF(*(pdata));
	    pdata+=2;
    }	    
    SPIx_ReadF(&dummy);
    while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
   {
    } 
}


//~ inline  void dmaSendData16(uint16_t *data, uint32_t n) 
//~ {  
     //~ dmaSendDataCont16(data,n);	
     //~ TFT_CS_SET;
//~ }



void dmaFill16(uint16_t color, uint32_t n) {
    //~ TFT_CS_RESET;
    uint8_t dummy;
    dmaSendCmdCont(LCD_GRAM);
    TFT_DC_SET;
#ifdef    COLOR_3BYTES
     uint8_t pdata[3];
   color_convert(color,pdata);
    while (n != 0) 
    {
	SPIx_WriteF(pdata[0]);
	SPIx_WriteF(pdata[1]);
	SPIx_WriteF(pdata[2]);
	n--;    
    }
#else	
    uint8_t *pdata = (uint8_t *)&color;
    while (n != 0) 
    {
	SPIx_WriteF(*(pdata+1));
	SPIx_WriteF(*(pdata));
	n--;    
    }
#endif	
	   SPIx_ReadF(&dummy);
    while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
   {
    } 
    
    //~ while(((hspi1.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
    //~ {
    //~ }  
    TFT_CS_SET;
}
void dmaFill16_2(uint16_t color,uint16_t seccolor, uint32_t n) {
    //~ TFT_CS_RESET;
    uint8_t dummy;
    dmaSendCmdCont(LCD_GRAM);
    TFT_DC_SET;
#ifdef    COLOR_3BYTES
     uint8_t pdata[3];
     uint8_t pdatas[3];
     color_convert(color,pdata);
     color_convert(seccolor,pdatas);
    while (n >0) 
    {
	SPIx_WriteF(pdata[0]);
	SPIx_WriteF(pdata[1]);
	SPIx_WriteF(pdata[2]);
	SPIx_WriteF(pdatas[0]);
	SPIx_WriteF(pdatas[1]);
	SPIx_WriteF(pdatas[2]);
	n--;    
    }
#else	
    uint8_t *pdata = (uint8_t *)&color;
    uint8_t *pdatas = (uint8_t *)&seccolor;
     //~ TFT_CS_RESET;	
    while (n > 0 ) 
    {
	SPIx_WriteF(*(pdata+1));
	SPIx_WriteF(*(pdata));
	SPIx_WriteF(*(pdatas+1));
	SPIx_WriteF(*(pdatas));
	n--;    
    }
#endif    
	SPIx_ReadF(&dummy);
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
}
static void LCD_pinsInit() 
{
	 TFT_CS_SET;
   //~ HAL_SPI_MspInit(&hspi1);	
    SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
    SPI_MASTER->CR1 &= ~SPI_CR1_DFF; // SPI 8
    SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
    //~ SPI_Cmd(SPI_MASTER, ENABLE);
}

void LCD_reset() {
     TFT_CS_SET;	
    TFT_RST_RESET;
    TFT_CS_SET;
    HAL_Delay(10);
    TFT_RST_SET;
    HAL_Delay(50);
}

void LCD_exitStandby() {
    dmaSendCmdCont(LCD_SLEEP_OUT);
    TFT_CS_SET;
    HAL_Delay(150);
    dmaSendCmdCont(LCD_DISPLAY_ON);
    TFT_CS_SET;
}
void LCD_idle(uint32_t mode) 
{
	dmaSendCmdCont(mode?LCD_IDMON:LCD_IDMOFF);
	TFT_CS_SET;
}
static void LCD_configure() {
    uint8_t count;
    uint8_t *address = (uint8_t *) init_commands;
    //~ SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
    //~ SPI_MASTER->CR1 &= ~SPI_CR1_DFF; // SPI 8
    //~ SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI

    //~ TFT_CS_RESET;
    while (1) {
        count = *(address++);
        if (count-- == 0) break;
        dmaSendCmdCont(*(address++));
        dmaSendDataCont8(address, count);
	    TFT_CS_SET;
        address += count;
    }
    //~ TFT_CS_SET;

    LCD_setOrientation(0);
}
void LCD_readSometing(uint8_t * buffr,uint8_t command,int commandLen)
{
        TFT_DC_RESET;
	TFT_CS_RESET;
	SPIx_WriteF(command);
	SPIx_ReadF(&buffr[0]);
	TFT_DC_SET;
	int k;
         for(k=0;k<commandLen;k++)
	 {
		SPIx_WriteF(0x00);
		SPIx_ReadF(&buffr[k]);
	 }
	TFT_CS_SET;
}


void LCD_init() {
	TFT_LED_RESET;
    LCD_pinsInit();
    //~ TFT_LED_SET;
    //~ HAL_Delay(100);
    //~ TFT_LED_RESET;
    //~ HAL_Delay(100);
    //~ TFT_LED_SET;
    //~ HAL_Delay(100);
    //~ TFT_LED_RESET;
    //~ HAL_Delay(100);
    //~ dmaInit();

    LCD_reset();
    TFT_LED_RESET;
    LCD_exitStandby();
    LCD_configure();
    //~ ReadID();
    TFT_LED_SET;
}

//</editor-fold>

//<editor-fold desc="LCD common operations">

void LCD_setOrientation(uint8_t o) {
    if (o == ORIENTATION_LANDSCAPE || o == ORIENTATION_LANDSCAPE_MIRROR) {
        screen_height = LCD_PIXEL_WIDTH;
        screen_width  = LCD_PIXEL_HEIGHT;
    } else {
        screen_height = LCD_PIXEL_HEIGHT;
        screen_width  = LCD_PIXEL_WIDTH;
    }
    //~ TFT_CS_RESET;
    dmaSendCmdCont(LCD_MAC);
    dmaSendDataCont8(&o, 1);
    TFT_CS_SET;
}

void LCD_setAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    uint16_t pointData[2];

    //~ TFT_CS_RESET;
    dmaSendCmdCont(LCD_COLUMN_ADDR);
    pointData[0] = x1;
    pointData[1] = x2;
    //~ LCD_setSpi16();
    dmaSendDataCont16(pointData, 2);
    //~ LCD_setSpi8();

    dmaSendCmdCont(LCD_PAGE_ADDR);
    pointData[0] = y1;
    pointData[1] = y2;
    //~ LCD_setSpi16();
    dmaSendDataCont16(pointData, 2);
    //~ LCD_setSpi8();
    //~ TFT_CS_SET;
}
#if 0
void LCD_WriteWord(uint16_t x1, uint16_t y1, uint32_t color) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1), (uint16_t) (y1));
    //~ LCD_setSpi16();
        uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	uint8_t pdata[3];
	pdata[0] = (color&0x3f)<<2;
	pdata[1] = ((color>>6)&0x3f)<<2;
	pdata[2] = ((color>>12)&0x3f)<<2;
	SPIx_WriteF(pdata[0]);
	SPIx_WriteF(pdata[1]);
	SPIx_WriteF(pdata[2]);
#else	
#endif    
	SPIx_ReadF(&dummy);
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
}

uint32_t LCD_ReadWord(uint16_t x1, uint16_t y1) 
{
	uint32_t color = 0; 
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1), (uint16_t) (y1));
    //~ LCD_setSpi16();
        uint8_t dummy=0xff;
	dmaSendCmdCont(LCD_RAMRD);
        TFT_DC_SET;
#ifdef    COLOR_3BYTES
	uint8_t pdata[3];
	SPIx_WriteF(dummy);
	SPIx_ReadF(&pdata[0]);
	SPIx_WriteF(dummy);
	SPIx_ReadF(&pdata[0]);
	SPIx_WriteF(dummy);
	SPIx_ReadF(&pdata[1]);
	SPIx_WriteF(dummy);
	SPIx_ReadF(&pdata[2]);
	color |= (pdata[0]&0b11111100)>>2;
	color |= ((pdata[1]&0b11111100)>>2)<<6;
	color |= ((pdata[2]&0b11111100)>>2)<<12;
#else	
#endif    
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
	return color;
}
#endif
void LCD_Write64bytes(uint16_t x1, uint16_t y1,uint8_t * adress) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+7), (uint16_t) (y1+3));
    //~ LCD_setSpi16();
        uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	uint16_t* sa =(uint16_t*)adress;
	int k;
	uint8_t pdata[3];
	for(k=0;k<32;k++)
	{
		uint32_t color = sa[k];
#ifdef CHECK_SUMM		
		color |= ((uint32_t)__builtin_parity(color)+1)<<16; //add check bit
#endif		
		pdata[0] = (color&0x3f)<<2;
		pdata[1] = ((color>>6)&0x3f)<<2;
		pdata[2] = ((color>>12)&0x3f)<<2;
		SPIx_WriteF(pdata[0]);
		SPIx_WriteF(pdata[1]);
		SPIx_WriteF(pdata[2]);
	}
#else	
#endif    
	SPIx_ReadF(&dummy);
	//~ while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	//~ {
	//~ } 
	TFT_CS_SET;
}

void  LCD_Read64bytes(uint16_t x1, uint16_t y1,uint8_t * adress) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+7), (uint16_t) (y1+3));
    //~ LCD_setSpi16();
        uint8_t dummy=0xff;
	dmaSendCmdCont(LCD_RAMRD);
        TFT_DC_SET;
#ifdef    COLOR_3BYTES
	uint16_t* sa =(uint16_t*)adress;
	uint8_t pdata[3];
	SPIx_WriteF(dummy);
	SPIx_ReadF(&pdata[0]);
	int k;
	for(k=0;k<32;k++)
	{
		uint32_t color = 0;
		SPIx_WriteF(dummy);
		SPIx_ReadF(&pdata[0]);
		SPIx_WriteF(dummy);
		SPIx_ReadF(&pdata[1]);
		SPIx_WriteF(dummy);
		SPIx_ReadF(&pdata[2]);
		color |= ((pdata[0]&0b11111100)>>2);
		color |= ((pdata[1]&0b11111100)>>2)<<6;
		color |= ((pdata[2]&0b11111100)>>2)<<12;
		sa[k] = color&0xffff;
#ifdef CHECK_SUMM		
		checkerror+= (((uint32_t)(__builtin_parity(color&0xffff)+1)<<16)!=(color&0xf0000));
#endif		
	}
#else	
#endif    
	//~ while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	//~ {
	//~ } 
	TFT_CS_SET;
}

void LCD_Write8x8line(uint16_t x1, uint16_t y1,uint8_t * adress) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+8-1), (uint16_t) (y1+8-1));
    //~ LCD_setSpi16();
        uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	//~ uint16_t* sa =(uint16_t*)adress;
	int k;
	for(k=0;k<8*8;k++)
	{
		SPIx_WriteF(adress[0]);
		SPIx_WriteF(adress[1]);
		SPIx_WriteF(adress[2]);
		adress+=3;
	}
#else	
#endif    
	SPIx_ReadF(&dummy);
	//~ while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	//~ {
	//~ } 
	TFT_CS_SET;
}
/*
void LCD_Write8line(uint16_t x1, uint16_t y1,uint8_t * adress) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+8-1), (uint16_t) (y1));
    //~ LCD_setSpi16();
        uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	//~ uint16_t* sa =(uint16_t*)adress;
	int k;
	for(k=0;k<8;k++)
	{
		SPIx_WriteF(adress[0]);
		SPIx_WriteF(adress[1]);
		SPIx_WriteF(adress[2]);
		adress+=3;
	}
#else	
#endif    
	SPIx_ReadF(&dummy);
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
}
*/
void LCD_FullRect3(uint16_t x1, uint16_t y1,uint8_t * adress,uint16_t w,uint16_t h) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+w-1), (uint16_t) (y1+h-1));
    //~ LCD_setSpi16();
        uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	//~ uint16_t* sa =(uint16_t*)adress;
	
	int k;
	for(k=w*h;k>0;k--)
	{
		SPIx_WriteF(adress[0]);
		SPIx_WriteF(adress[1]);
		SPIx_WriteF(adress[2]);
		//~ adress+=3;
	}
#else	
#endif    
	SPIx_ReadF(&dummy);
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
}
void LCD_FullRect6(uint16_t x1, uint16_t y1,uint8_t * adress,uint8_t * adress1,uint16_t w,uint16_t h) 
{
        LCD_setAddressWindow(x1, y1, (uint16_t) (x1+w-1), (uint16_t) (y1+h-1));
    //~ LCD_setSpi16();
       uint8_t dummy;
       dmaSendCmdCont(LCD_GRAM);
       TFT_DC_SET;
#ifdef    COLOR_3BYTES
	//~ uint16_t* sa =(uint16_t*)adress;
	
	int k;
	for(k=w*h/2;k>0;k--)
	{
		SPIx_WriteF(adress[0]);
		SPIx_WriteF(adress[1]);
		SPIx_WriteF(adress[2]);
		SPIx_WriteF(adress1[0]);
		SPIx_WriteF(adress1[1]);
		SPIx_WriteF(adress1[2]);
		//~ adress+=3;
	}
#else	
#endif    
	SPIx_ReadF(&dummy);
	while(((hspi1.Instance->SR) & SPI_FLAG_BSY) != RESET)
	{
	} 
	TFT_CS_SET;
}


void LCD_fillRect(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t color) {
     uint8_t pdata[3];
     color_convert(color,pdata);
     LCD_FullRect3(x1,y1,pdata,w,h); 
}
void LCD_fillRect2(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t color,uint16_t seccolor) 
{
     uint8_t pdata[3];
     uint8_t psdata[3];
     color_convert(color,pdata);
     color_convert(seccolor,psdata);
     LCD_FullRect6(x1,y1,pdata,psdata,w,h); 
}
	//~ y	
	//~ x 0 1 2 3
	//~ 	 0 1 2 3

uint16_t LCD_getWidth() {
    return screen_width;
}

uint16_t LCD_getHeight() {
    return screen_height;
}
//~ void LCD_Draw_Pixel(uint16_t x,uint16_t y,uint16_t color)
//~ {
	//~ LCD_fillRect(x,y,1,1,color);
//~ }
#include "5x5_font.h"
void LCD_Draw_Char(char Character, int16_t X, int16_t Y, uint16_t Colour, uint16_t Size, uint16_t Background_Colour) 
{
	//~ flagReinit = 1;
		uint8_t 	function_char;
    int16_t 	i,j;
		
	function_char = Character;
		
        if (function_char < 0x20) 
	{
		Character = 0;
	} 
	else 
	{
		function_char -= 32;
	}
   	
	char temp[CHAR_WIDTH];
	uint8_t k;
	for( k = 0; k<CHAR_WIDTH; k++)
	{
		temp[k] = font[function_char*CHAR_WIDTH+k];
	}
		
    // Draw pixels
		LCD_fillRect(X, Y, CHAR_WIDTH*Size, CHAR_HEIGHT*Size, Background_Colour);
    for (j=0; j<CHAR_WIDTH; j++) {
        for (i=0; i<CHAR_HEIGHT; i++) { 
            if (temp[i] & (1<<(CHAR_WIDTH-1-j))) {			
								//~ LCD_fillRect(X+(j*Size), Y+(i*Size), Size,Size, Colour);
							LCD_fillRect(X+(j*Size), Y+(i*Size), Size,Size, Colour);
            }						
        }
    }
}

/*Draws an array of characters (fonts imported from fonts.h) at X,Y location with specified font colour, size and Background colour*/
/*See fonts.h implementation of font on what is required for changing to a different font when switching fonts libraries*/
void  LCD_Draw_Text(const char* Text, int16_t X, int16_t Y, uint16_t Colour, uint16_t Size, uint16_t Background_Colour)
{
    while (*Text) {
        LCD_Draw_Char(*Text, X, Y, Colour, Size, Background_Colour);
        X += CHAR_WIDTH*Size;
	Text++;    
    }
}

