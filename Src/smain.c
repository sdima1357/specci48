#include "main.h"
#include "stm32f1xx_hal.h"
//~ #include "fatfs.h"

/* USER CODE BEGIN Includes */
#include "commands.h"
#include "core.h"
#include "5x5_font.h"
#include "stm32_adafruit_sd.h"
#include "fatfs.h"
#include "ff_gen_drv.h"
//~ #include "5x5_font.h"
extern Diskio_drvTypeDef  SD_Driver;
extern SPI_HandleTypeDef hspi1;
void  SPIx_Error1 (void);
 void MX_SPI1_Init(int);

//~ #include "ff_gen_drv.h"
//~ #include "sd_diskio.h"
//~ #include "fatfs_storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_ROM.h"
uint16_t border;
extern int32_t tstates;
//~ void SDCard_Config(void);
//#define  poke(addr,value) writeByte(addr,value)
#include "z80.h"
inline uint8_t readByte(uint16_t adress);
inline void writeByte(uint16_t adress,uint8_t data);
uint8_t  VIDEO_RAM[0x5800-0x4000];
uint8_t  ATTR_RAM[0x5B00-0x5800];
uint8_t  ATTR_RAM_MOD[(0x5B00-0x5800)>>3];

void clearAttr()
{
	int k;
	for(k=0;k<((0x5B00-0x5800)>>3);k++)
	{
		ATTR_RAM_MOD[k] = 0;
	}
}
void setAttr()
{
	int k;
	for(k=0;k<((0x5B00-0x5800)>>3);k++)
	{
		ATTR_RAM_MOD[k] = 0xff;
	}
}
void  poke(uint16_t addr,uint8_t value) 
{
	if(addr<0x4000)
	{
	}
	else if(addr<0x5800)
	{
		// tile address from memaddr;
		uint16_t pa = (addr&0x00ff) | (addr&0x1800)>>3;
		ATTR_RAM_MOD[pa>>3] |= (1<<(pa&0x3));
		VIDEO_RAM[addr-0x4000]=value;
	}
	else if(addr<0x5B00)
	{
		uint16_t pa = addr-0x5800;
		ATTR_RAM_MOD[pa>>3] |= (1<<(pa&0x3));
		ATTR_RAM[pa]= value;
	}
	else
	{
		writeByte(addr,value);
	}
}

//~ #define  peek(addr) (((uint16_t)addr<(uint16_t)0x4000)?ROM[addr]:readByte(addr))
inline u8  peek(uint16_t addr) 
{
	u8 res;
	if(addr<0x4000)
	{
		res = ROM[addr];
	}
	else if (addr<0x5800)
	{
		res = VIDEO_RAM[addr-0x4000];
	}
	else if (addr<0x5B00)
	{
		res = ATTR_RAM[addr-0x5800];
	}
	else
	{
		res = readByte(addr);
	}
	return res;
}

void poke16(u16 addr, u16 value)
{
	poke(addr, value);
	poke(addr+1, value>>8);
}

u16 peek16(u16 addr)
{
	return ((peek(addr+1)<<8)|peek(addr));
}

u8 in(u16 port)
{
	u8 input;
	if ((port&0x00FF)==0xFE)//перехват порта 0xFE
	{
		
#ifdef IN_OUT	
		GPIOC->ODR&=0x00FF;
		GPIOC->ODR|=port&0xFF00;
		
		for (pa=0; pa<10; pa++)
		{
			o++;
		}
		input=(GPIOA->IDR&0x1F);
	
		if ((ADC1->DR)>6)
		{
			input|=0x40;
		}
#endif		
			return (input);
	}
	else
	{
		return (0xff);
	}
	

}

void out(u16 port, u8 value)
{
	if ((port&0xFF)==0x00FE)//перехват порта 0xFE
	{
		border=value;//D[0-2]цвет бордюра 
		if(value&(0b11000)) //sound bit
		{
			SOUND_GPIO_Port->BSRR = SOUND_Pin;
		}
		else
		{
			SOUND_GPIO_Port->BSRR = (uint32_t)SOUND_Pin<<16U;
		}
	}
}

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
FATFS SD_FatFs;  /* File system object for SD card logical drive */
char SD_Path[4]; /* SD card logical drive path */

#if 0
#define ADDR_FLASH_PAGE_63    ((uint32_t)0x0800FC00) /* Base @ of Page 63, 1 Kbytes */
#define ADDR_FLASH_PAGE_64    ((uint32_t)0x08010000) /* Base @ of Page 64, 1 Kbytes */

//~ char* pDirectoryFiles[MAX_BMP_FILES];
/* USER CODE END PV */


int erase_Flash()
{
  FLASH_EraseInitTypeDef EraseInitStruct;
  uint32_t PAGEError = 0;
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = ADDR_FLASH_PAGE_63;
  EraseInitStruct.NbPages     = 1;//(FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE;
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) == HAL_OK)
  {
	return 1;  
  }
   return 0;
}

int  write_Flash(uint32_t Address,uint32_t data)
{
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, data) == HAL_OK)
	{
		return 1;
	}
	return 0;
     //~ HAL_FLASH_Unlock();
     //~ __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
     //~ FLASH_Erase_Sector(FLASH_SECTOR_6, VOLTAGE_RANGE_3);
     //~ HAL_FLASH_Program(TYPEPROGRAM_WORD, FlashAddress, data);
     //~ HAL_FLASH_Lock();
}
char* MontTable[] =
{
	"JANUARY",
	"FEBRUARY",
	"MARCH",
	"APRIL",
	"MAY", 
	"JUNE",
	"JULY", 
	"AUGUST",
	"SEPTEMBER",
	"OCTOBER", 
	"NOVEMBER",
	"DECEMBER"
};
static uint8_t RTC_ByteToBcd2(uint8_t Value)
{
  uint32_t bcdhigh = 0U;
  
  while(Value >= 10U)
  {
    bcdhigh++;
    Value -= 10U;
  }
  
  return  ((uint8_t)(bcdhigh << 4U) | Value);
}

/**
  * @brief  Converts from 2 digit BCD to Binary.
  * @param  Value: BCD value to be converted
  * @retval Converted word
  */
static uint8_t RTC_Bcd2ToByte(uint8_t Value)
{
  uint32_t tmp = 0U;
  tmp = ((uint8_t)(Value & (uint8_t)0xF0) >> (uint8_t)0x4) * 10U;
  return (tmp + (Value & (uint8_t)0x0F));
}


char* getMontString(uint8_t num)
{
	return MontTable[RTC_Bcd2ToByte(num)-1];
}
//~ int strlen(char* pnt)
//~ {
	//~ int n=0;
	//~ while(*pnt++) n++;
	//~ return n;
//~ }
#endif
char * printNum(int32_t num)
{
	static char buffer[0x20];
	char* pbuff = &buffer[0x20-1];
	int sgn = (num<0)?(-1):(1);
	num *= sgn;
	*pbuff = 0;	
	pbuff--;
	*pbuff = '0';
	if(num)
	{	    
		while(num)
		{
			*pbuff = (num%10)+'0';    
			num/=10;
			pbuff--;    
		}
		pbuff++;   
		if(sgn<0)
		{
			pbuff--;    
			*pbuff = '-';
			//~ pbuff++;   
		}
		
	}
	return  pbuff;
}
char * printNumU(uint64_t num)
{
	static char buffer[0x20];
	char* pbuff = &buffer[0x20-1];
	*pbuff = 0;	
	pbuff--;
	*pbuff = '0';
	if(num)
	{	    
		while(num)
		{
			*pbuff = (num%10)+'0';    
			num/=10;
			pbuff--;    
		}
		pbuff++;   
	}
	return  pbuff;
}
//~ char * printNum(int32_t num)
//~ {
    //~ static char buffer[0x10];
    //~ char* pbuff = &buffer[0x10-1];
    //~ *pbuff = 0;	
    //~ pbuff--;
    //~ *pbuff = '0';
    //~ if(num)
    //~ {	    
	    //~ while(num)
	    //~ {
		//~ *pbuff = (num%10)+'0';    
		//~ num/=10;
		//~ pbuff--;    
	    //~ }
	    //~ pbuff++;   
    //~ }
    //~ return  pbuff;
//~ }
char * printNum16(uint32_t num)
{
    static char buffer[0x10];
    char* pbuff = &buffer[0x10-1];
    *pbuff = 0;	
    pbuff--;
    *pbuff = '0';
    if(num)
    {	    
	    while(num)
	    {
		 int snum =    (num%16);
		    if(snum<10)
		    {
			*pbuff = snum+'0';    
		    }
		    else
		    {
			    *pbuff = snum+'A'-10;    
		    }
		    
		num/=16;
		pbuff--;    
	    }
	    pbuff++;   
    }
    return  pbuff;
}
char * printNum16_2(uint32_t num)
{
    static char buffer[3];
    buffer[2] = 0;	
    buffer[1] = (num%16)+'0';	
    buffer[0] = ((num/16)%16)+'0';	
    return  &buffer[0];
}

//Check if Touchpad was pressed. Returns TOUCHPAD_PRESSED (1) or TOUCHPAD_NOT_PRESSED (0)
//~ #if 0
uint8_t TP_Read_Coordinates(int32_t Coordinates[2]);
uint8_t TP_Touchpad_Pressed(void);
void paintCross(int32_t x,int32_t y,int32_t size,int32_t color)
{
	LCD_fillRect(x,y-size/2,1,size,color);
	LCD_fillRect(x-size/2,y,size,1,color);
}
void clearFullScreen()
{
	LCD_fillRect(0,0,LCD_getWidth(),LCD_getHeight(),BLACK);	
}
#if 0
inline FLOAT det3  (	
			FLOAT a,FLOAT b,FLOAT c,
			FLOAT d,FLOAT e,FLOAT f,
			FLOAT g,FLOAT h,FLOAT i
			)
{
	return a*e*i +b*f*g+ c*d*h - a*f*h - b*d*i - c*e*g;
}

inline FLOAT mat3x3Invert(FLOAT *p,FLOAT* ff)
{
		const  FLOAT  b11= (p[0]);	
		const  FLOAT  b12 =(p[1]);	
		const  FLOAT  b13 =(p[2]);
		const  FLOAT  b21 =(p[3]);	
		const  FLOAT  b22 =(p[4]);	
		const  FLOAT  b23 =(p[5]);	
		const  FLOAT  b31 =(p[6]);	
		const  FLOAT  b32 =(p[7]);	
		const  FLOAT  b33 =(p[8]);	
		ff[0*3+0] = (b22*b33-b32*b23);ff[0*3+1] = (b13*b32-b33*b12);ff[0*3+2] = (b12*b23-b22*b13);
		ff[1*3+0] = (b23*b31-b33*b21);ff[1*3+1] = (b11*b33-b31*b13);ff[1*3+2] = (b13*b21-b23*b11);
		ff[2*3+0] = (b21*b32-b31*b22);ff[2*3+1] = (b12*b31-b32*b11);ff[2*3+2] = (b11*b22-b21*b12);
		return det3(
							b11,b12,b13,
							b21,b22,b23,
							b31,b32,b33
						);;
}	

#define N_MESU 9
void touchSetting()
{
	sTouchCalibration* calib = getCalibr();
	uint32_t * flashp = (uint32_t *) ADDR_FLASH_PAGE_63;
	int32_t Coordinates[2];
	
	//~ if((flashp[0]!=0xffffffff)&&!force)
	{
		uint32_t * rpnt = (uint32_t *)(&calib->Transform[0][0]);
		int kk =0;
		for(kk=0;kk<6;kk++)
		{
			rpnt[kk] = flashp[kk];
		}
	}	
	Coordinates[0] = 0;
	Coordinates[1] = 0;
	
	Coordinates[0] = -1;
	LCD_Draw_Text("T me!",LCD_getWidth()/2-2*8*CHAR_WIDTH/2,LCD_getHeight()/2-2*CHAR_HEIGHT/2, GREEN, 2, BLACK);
	//~ while(Coordinates[0]==-1)
	{
		while(!TP_Touchpad_Pressed())
		{
			//
		}
		TP_Read_Coordinates(Coordinates);
		//~ LCD_Draw_Text(printNum16(Coordinates[0]),10,140, GREEN, 2, BLACK);
		//~ LCD_Draw_Text(printNum16(Coordinates[1]),10,140+20, GREEN, 2, BLACK);
	}
}
void reCalibrateTouch(int force)
{
FLOAT VTP[3][N_MESU];
FLOAT RTP[3][N_MESU];
FLOAT VTP_VTP_T_I[3][3];
FLOAT RTP_VTP_T[3][3];
FLOAT VTP_VTP_T[3][3];
	sTouchCalibration* calib = getCalibr();
	int32_t Coordinates[2];
	int32_t i;
	int32_t j;
	//~ LCD_fillRect(0,0,LCD_getWidth(),LCD_getHeight(),BLACK);
	//~ LCD_Draw_Text(printNum(sizeof(float)),30,LCD_getWidth()/4, YELLOW, 4, BLACK);  
	//~ LCD_Draw_Text(printNum(sizeof(sTouchCalibration)),130,LCD_getWidth()/4, YELLOW, 4, BLACK);  
	//~ HAL_Delay(20000);
	//~ if(HAL_RTCEx_BKUPRead(&hrtc,RTC_BKP_DR7)==0x1235)
	//~ {
		//~ int kk;
		//~ uint16_t * rpnt = (uint16_t *) (&calib->Transform[0][0]);
		//~ for(kk=0;kk<12;kk++)
		//~ {
			//~ uint16_t val = HAL_RTCEx_BKUPRead(&hrtc,RTC_BKP_DR8+kk);
			//~ rpnt[kk] = val;
			//~ LCD_Draw_Text(printNum16(val),130,LCD_getWidth()/4, YELLOW, 4, BLACK);  
			//~ HAL_Delay(4000);
		//~ }
		
	//~ }
	uint32_t * flashp = (uint32_t *) ADDR_FLASH_PAGE_63;
	
	if((flashp[0]!=0xffffffff)&&!force)
	{
		uint32_t * rpnt = (uint32_t *)(&calib->Transform[0][0]);
		int kk =0;
		for(kk=0;kk<6;kk++)
		{
			rpnt[kk] = flashp[kk];
		}
	}
	//~ if(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) != 0x32F2||calib->Transform[0][0]==0.0f)
	else
	{
	calib->Transform[0][0] = (FLOAT)1.0;	calib->Transform[0][1] = (FLOAT)0.0;	calib->Transform[0][2] = (FLOAT)0.0;
	calib->Transform[1][0] = (FLOAT)0.0;	calib->Transform[1][1] = (FLOAT)1.0;	calib->Transform[1][2] = (FLOAT)0.0;
	
	int testX[]	={20,(int32_t)(LCD_getWidth())/2,(int32_t)(LCD_getWidth())  -  20};
	int testY[]	={20,(int32_t)(LCD_getHeight())/2,(int32_t)(LCD_getHeight())  -  20};
	
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			clearFullScreen();
			LCD_Draw_Text("press cross",30,LCD_getWidth()/4, j?YELLOW:RED, 2, BLACK);  
			int cX = 	testX[i];
			int cY = 	testY[j];
			paintCross(cX,cY,13,YELLOW);
			int ind = i*3+j;
			RTP[0][ind] = cX;
			RTP[1][ind] = cY;
			RTP[2][ind] = (FLOAT)1.0;
			
			Coordinates[0] = 0;
			Coordinates[1] = 0;
			
			Coordinates[0] = -1;
			while(Coordinates[0]==-1)
			{
				while(!TP_Touchpad_Pressed())
				{
					//
				}
				TP_Read_Coordinates(Coordinates);
				LCD_Draw_Text(printNum16(Coordinates[0]),10,140, GREEN, 2, BLACK);
				LCD_Draw_Text(printNum16(Coordinates[1]),10,140+20, GREEN, 2, BLACK);
			}
			int x0 = Coordinates[0];
			int y0 = Coordinates[1];
			VTP[0][ind] = x0;
			VTP[1][ind] = y0;
			VTP[2][ind] =  (FLOAT)1.0;
			paintCross(cX,cY,13,BLACK);
			//~ LCD_Draw_Text(printNum(x0),10,140, GREEN, 2, BLACK);
			//~ LCD_Draw_Text(printNum(y0),10,140+20, GREEN, 2, BLACK);
			
			HAL_Delay(300);
		}
	}
	//~   RTP=A*VTP;
	// ~ (RTP*VTP')*INV(VTP*VTP') = A;
	int X;	
	int Y;	
	// RTP*VTP'
	// 
        for(Y=0;Y<3;Y++)
	{
		for(X=0;X<3;X++)
		{
			FLOAT summRVT = (FLOAT)0;
			FLOAT summVVT = (FLOAT)0;
			for(i=0;i<N_MESU;i++)
			{
				summRVT+=RTP[Y][i]*VTP[X][i];
				summVVT+=VTP[Y][i]*VTP[X][i];
			}
			RTP_VTP_T[Y][X] = summRVT;
			VTP_VTP_T[Y][X] = summVVT;
		}
	} 	
	
	// invert VTP_VTP_T
	FLOAT determinant = mat3x3Invert(&VTP_VTP_T[0][0],&VTP_VTP_T_I[0][0]);
	FLOAT scale = ((FLOAT)1.0)/determinant;
	// multiply RTP_VTP_T*VTP_VTP_T_I
	FLOAT RESULT[3][3];
        for(Y=0;Y<3;Y++)
	{
		for(X=0;X<3;X++)
		{
			FLOAT summRVT = (FLOAT)0;
			for(i=0;i<3;i++)
			{
				summRVT+=RTP_VTP_T[Y][i]*VTP_VTP_T_I[i][X];
			}
			RESULT[Y][X] = summRVT*scale;
		}
	}
	clearFullScreen();
	for(Y=0;Y<3;Y++)
	{
		for(X=0;X<3;X++)
		{
			if(Y<2)
			{
				calib->Transform[Y][X] = RESULT[Y][X];
			}
			if(X<2)
			{		
				//~ LCD_Draw_Text(printNum((int)(RESULT[Y][X]*10000)),10+X*70,Y*30, GREEN, 2, BLACK);
			}
			else
			{
				//~ LCD_Draw_Text(printNum((int)(RESULT[Y][X])),10+X*70,Y*30, GREEN, 2, BLACK);
			}				
		}
	}
	//~ HAL_Delay(4000);
	if(0)
	{
		uint32_t * rpnt = (uint32_t *) (&calib->Transform[0][0]);
		uint32_t flashp = ADDR_FLASH_PAGE_63;
		int kk =0;
		HAL_FLASH_Unlock();
		int res=erase_Flash();
		for(kk=0;kk<6;kk++)
		{
			res = write_Flash(flashp,rpnt[kk]);
			flashp+=4;
		}
		HAL_FLASH_Lock();
		LCD_Draw_Text(printNum16(res),10,140, GREEN, 2, BLACK);
			
	}
	
	//~ {
		//~ int kk;
		//~ HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR7,0x1235);
		//~ uint16_t * rpnt = (uint16_t *) (&calib->Transform[0][0]);
		//~ for(kk=0;kk<12;kk++)
		//~ {
			//~ HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR8+kk,rpnt[kk]);
			//~ LCD_Draw_Text(printNum16(rpnt[kk]),130,LCD_getWidth()/4, YELLOW, 4, BLACK);  
			//~ HAL_Delay(4000);
		//~ }
	//~ }
		#if 0
		{
			clearFullScreen();
			int X,Y;
			char buff[0x20];
			LCD_Draw_Text("results:",10,200, GREEN, 2, BLACK);
			for(Y=0;Y<2;Y++)
			{
				for(X=0;X<3;X++)
				{
					int sn = 1000*calib->Transform[Y][X];
					int hn = (sn<0?-sn:sn) / 1000;
					int ln  = (sn<0?-sn:sn) - hn*1000; 
					sprintf(buff," %3d.%03d",hn,ln);
					buff[0] = sn<0?'-':' ';
					LCD_Draw_Text(buff,10,(Y*3+X)*30, GREEN, 2, BLACK);
				}
			}
		}
		#endif
		HAL_Delay(2000);
	}
	
	// test 10 points
	//~ for(i=0;i<10;i++)
	//~ {
		//~ Coordinates[0] = 0;
		//~ Coordinates[1] = 0;
		
		//~ Coordinates[0] = -1;
		//~ paintCross(100,100,13,BLACK);	
		//~ while(Coordinates[0]==-1)
		//~ {
			//~ while(!TP_Touchpad_Pressed())
			//~ {
				//~ //
			//~ }
			//~ TP_Read_Coordinates(Coordinates);
		//~ }
		//~ clearFullScreen();
		//~ int x0 = Coordinates[0];
		//~ int y0 = Coordinates[1];
		//~ LCD_Draw_Text(printNum(x0),10,140, GREEN, 2, BLACK);
		//~ LCD_Draw_Text(printNum(y0),10,140+20, GREEN, 2, BLACK);
		//~ paintCross(x0,y0,13,GREEN);	
		//~ HAL_Delay(200);
	//~ }
	//~ clearFullScreen();
}
#endif
//~ #endif
// keyboard
//~ struct sKey;
#if 0
struct  sKeys 
{
	int16_t x;
	int16_t y;
	int16_t w;
	int16_t h;
	int16_t scale;
	int16_t response;
	int16_t SYMB_color;
	int16_t ON_color;
	int16_t OFF_color;
	char text[10];
	int16_t state;
	struct  sKeys *   next;
	
} ;
typedef struct sKeys sKey;

sKey* parent 			= NULL;
int16_t defSYMB_color  	= YELLOW;
int16_t defON_color          =  WHITE;
int16_t defOFF_color         =  BLACK;

sKey ** getLastKey()
{
	sKey** curr = &parent;
	while(*curr)
	{	
		curr = &((*curr)->next);
	}
	return curr;
}
void clearKeys()
{
	sKey* curr = parent;
	while(curr)
	{
		sKey* next = curr->next;
		free(curr);
		curr = next;
	}
	parent = NULL;
}

void paintKeys()
{
	sKey* curr = parent;
	while(curr)
	{
		LCD_Draw_Text(curr->text,curr->x,curr->y, curr->SYMB_color, curr->scale, curr->state?curr->ON_color:curr->OFF_color);
		curr = curr->next;
	}
}

sKey* findKeyPressed(int x,int y)
{
	sKey* curr = parent;
	while(curr)
	{
		int tx = x-curr->x;
		int ty = y-curr->y;
		if(tx>0&&tx<curr->w&&ty>0&&ty<curr->h)
		{
			return curr;
		}
		curr = curr->next;
	}
	return curr;
}

void addKey(char* text,int16_t response,int16_t x, int16_t y,int16_t scale)
{
	int len  = strlen(text);
	if(len>9)  return;
	
	sKey** last = getLastKey();
	*last = malloc(sizeof(sKey));
	sKey* curr = *last;
	
	curr->x = x;
	curr->y = y;
	curr->scale = scale;
	curr->response = response;
	curr->w = len*scale*CHAR_WIDTH;
	curr->h = scale*CHAR_HEIGHT;
	curr->SYMB_color = defSYMB_color;
	curr->ON_color = defON_color;
	curr->OFF_color = defOFF_color;
	curr->next = NULL;
	curr->state =0;
	strcpy(&curr->text[0],text);
}
#endif

#define EXIST 		0x200 
#define MODIFIED 	0x400 
//~ #define TO_DISPLAY	0x800 
#define BLOCKS ((0x10000-0x5B00)/64)
struct block
{
	uint8_t  X;  
	uint8_t  Y; 
	uint16_t  flag_line; 
	//~ uint8_t  flags; // 0x200 - exist mask  0x400 modified by write 	//~ uint8_t  line;  // line - pointer
}  Blocks[BLOCKS];

#define NUM_LINES (96)

struct cacheLinePool
{
	uint8_t    cacheLine[64];
	uint16_t  currentBlockNumber;
	uint32_t  lastTimeTick;
}  Lines[NUM_LINES];

uint32_t  timeTick = 0;
uint16_t  missSaveMemory = 0;
uint16_t  missReadMemory = 0;

#define N_SCALE 4
#define WW  (320/N_SCALE)
#define HH   (240/N_SCALE)
#define SW  ((256+8)/N_SCALE)
#define SH   ((192+8)/N_SCALE)
//~ #define SH   ((192)/N_SCALE)
#define LX  ((WW-SW)/2)
#define LY  ((HH-SH)/2)
#define BX   (8/N_SCALE)
#define BY  (4/N_SCALE)

int insizeXY(int x,int y)
{
	if(x>=LX&&x<LX+SW&&y>=LY&&y<LY+SH)
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

void initBlocksAndLines()
{
	
	int k=0;
	//~ int blockX = 0;
	//~ int blockY = 0;
	// each block 4x4 pixels
	// all screen is  320/4*240/4 blocs;
	// allocated to spessi screen is (256+8)/4*(192)/4
	int cnt = 0;
	int y,x,yy,xx;
	for(y=0;y<HH;y+=BY)
	{
		for(x=0;x<WW;x+=BX)
		{
			int free = 1;
			for(yy=0;yy<BY;yy++)
			{
				for(xx=0;xx<BX;xx++)
				{
					if(insizeXY(x+xx,y+yy))
					{
						free = 0;
					}
				}
			}
			Blocks[cnt].X = x;
			Blocks[cnt].Y = y;
			Blocks[cnt].flag_line = 0; //not exist
			cnt+= free;
			if(cnt==BLOCKS)
			{
				goto  ENOU;
			}				
		}
		
	}
#if 0
	int x,y;
	//~ char rb[0x10];
	for(y=0;y<240/4;y++)
	{
		if(y<(240/4/2-(192)/4/2)||y>=(240/4/2+(192)/4/2))
		{
			for(x=0;x<320/4;x++)
			{
				Blocks[k].X = x;
				Blocks[k].Y = y;
				Blocks[k].flag_line = 0; //not exist
				k++;
				if(k==BLOCKS)
				{
					goto  ENOU;
				}
				//all blocs
			}
		}
		else
		{
			for(x=0;x<320/4;x++)
			{
				if(x<(320/4/2-(256+8)/4/2)||x>=(320/4/2+(256+8)/4/2))
				{
					Blocks[k].X = x;
					Blocks[k].Y = y;
					Blocks[k].flag_line = 0; //not exist
					k++;
					if(k==BLOCKS)
					{
						goto  ENOU;
					}
				}
				//all blocs
			}
		}
		//~ sprintf(rb,"%05d",k);
		//~ HAL_Delay(100);
		//~ for(k=0;k<BLOCKS;k++)
		//~ {
			// calculate X and Y
		//~ }	
	}
#endif	
ENOU:
	
	LCD_Draw_Text(printNum(cnt),4,LCD_getHeight()/2, YELLOW, 4, BLACK);   
	HAL_Delay(500);
	for(k=0;k<NUM_LINES;k++)
	{
		Lines[k].currentBlockNumber = k;
		Lines[k].lastTimeTick = 0;
		Blocks[k].flag_line           = EXIST|k;
		//~ Blocks[k].line             = k;
	}
}


int  findOldestLine()
{
		// find oldest line for commit
	int   oldestLineIndex = 0;
	uint32_t timediff       = 0;
	int k;
	for(k=0;k<NUM_LINES;k++)
	{
		uint32_t diffval = timeTick-Lines[k].lastTimeTick;
		if(diffval>timediff)
		{
			timediff = diffval;
			oldestLineIndex = k;
		}
	}
	return oldestLineIndex;
}
//~ void  LCD_Read32bytes(uint16_t x1, uint16_t y1,uint8_t * adress) ;
//~ void  LCD_Write32bytes(uint16_t x1, uint16_t y1,uint8_t * adress) ;

void writeCache64bIfmodified(uint16_t blockNumber,uint8_t * data)
{
	if(Blocks[blockNumber].flag_line&MODIFIED)
	{
		uint16_t X = (Blocks[blockNumber].X)*4;
		uint16_t Y = (Blocks[blockNumber].Y)*4;
		LCD_Write64bytes(X,Y,data);
		missSaveMemory++;
		// write lcd block32;
	}
	// just clear flags;
	Blocks[blockNumber].flag_line = 0; 
}
void readCache64b(uint16_t blockNumber,uint8_t * data,uint16_t lineNum)
{
	uint16_t X = (Blocks[blockNumber].X)*4;
	uint16_t Y = (Blocks[blockNumber].Y)*4;
	
	LCD_Read64bytes(X,Y,data);
	missReadMemory++;
	Blocks[blockNumber].flag_line = EXIST|lineNum; 
	//~ Blocks[blockNumber].line   = ;
	// read lcd block32;
}


inline uint8_t readByte(uint16_t adress)
{
	timeTick++;
	uint16_t blockAdress          =  (adress-0x5B00)>>6;
	struct block* bl                 = &Blocks[blockAdress];
	struct cacheLinePool* line = &Lines[bl->flag_line&0x1ff];
	if(!(bl->flag_line&EXIST))
	{
		int oldestLineIndex = findOldestLine();
		// commit line to extern mem if it touched
		line = &Lines[oldestLineIndex];
		writeCache64bIfmodified(line->currentBlockNumber,line->cacheLine);
		// read right line from extern mem && mark as last read
		//~ 
		readCache64b(blockAdress,line->cacheLine,oldestLineIndex);
		line->currentBlockNumber = blockAdress;
		// 
		
	}
	//mark as last read
	line->lastTimeTick = timeTick;
	return line->cacheLine[adress&0x3f];
}
inline void writeByte(uint16_t adress,uint8_t data)
{
	timeTick++;
	//~ if(adress>=(uint16_t)0x5B00)
	//~ {
		uint16_t blockAdress =  (adress-0x5B00)>>6;
		struct block* bl =        &Blocks[blockAdress];
		struct cacheLinePool* line = &Lines[bl->flag_line&0x1ff];
		if(!(bl->flag_line&EXIST))
		{
			
			// find oldest line for commit
			int oldestLineIndex = findOldestLine();
			// commit line to extern mem if it touched
			line = &Lines[oldestLineIndex];
			writeCache64bIfmodified(line->currentBlockNumber,line->cacheLine);
			// read right line from extern mem && mark as last read
			//~ 
			readCache64b(blockAdress,line->cacheLine,oldestLineIndex);
			line->currentBlockNumber = blockAdress;
			// 
		}
		else
		{
		}
		line->lastTimeTick = timeTick;
		line->cacheLine[adress&0x3f] = data;
		bl->flag_line|=MODIFIED;//|TO_DISPLAY;
	//~ }
}
/*
int readLine32(uint16_t adress,uint8_t* to)
{
	timeTick++;
	uint16_t blockAdress          =  (adress-0x4000)>>5;
	struct block* bl                 = &Blocks[blockAdress];
	struct cacheLinePool* line = &Lines[bl->flag_line&0x1ff];
	if(!(bl->flag_line&EXIST))
	{
		int oldestLineIndex = findOldestLine();
		// commit line to extern mem if it touched
		line = &Lines[oldestLineIndex];
		writeCache32bIfmodified(line->currentBlockNumber,line->cacheLine);
		// read right line from extern mem && mark as last read
		//~ 
		readCache32b(blockAdress,line->cacheLine,oldestLineIndex);
		line->currentBlockNumber = blockAdress;
		// 
		
	}
	//mark as last read
	line->lastTimeTick = timeTick;
	int k;
	int s = bl->flag_line&TO_DISPLAY;
	bl->flag_line&=~TO_DISPLAY;
	for(k=0;k<32;k++)
	{
		 to[k] = line->cacheLine[k];
	}
	return s;
	//~ return line->cacheLine[adress&0x1f];
}
*/


extern u8 opcode;
extern u8 screen_IRQ;
/* USER CODE END 0 */
void wait_any_key()
{
	while(!TP_Touchpad_Pressed())
	{
		//
	}
}
void memory_test()
{
  {
	  //memory test
	  int block;
	  int k;
	  uint8_t bts[64];
	  int flag       = 1;
	  int blockErr=-1;
	  for(block=0;block<BLOCKS;block++)
	  {
		  for(k=0;k<64;k++)
		  {
			  bts[k] = ((block+k)^0x55)&0xff;
		  }
		  int X = Blocks[block].X*4;
		  int Y = Blocks[block].Y*4;
		  LCD_Write64bytes(X,Y,bts);
	  }
	  
	  for(block=0;block<BLOCKS;block++)
	  {
		  int X = Blocks[block].X*4;
		  int Y = Blocks[block].Y*4;
		  for(k=0;k<64;k++)
		  {
			  bts[k] = 0;
		  }
		  LCD_Read64bytes(X,Y,bts);
		  for(k=0;k<64;k++)
		  {
			  uint8_t btt= ((block+k)^0x55)&0xff;
			  if(bts[k] != btt)
			  {
				flag = 0;
				blockErr =  block;	
			  }
		  }
	  }
	  
	  LCD_Draw_Text(flag?"OK":"Memory Error",10,10, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNum16(blockErr),10,30, GREEN, 2, BLACK);
	  if(flag)
	  {
		HAL_Delay(100);
	  }
	  else
	  {
		HAL_Delay(1000);
		wait_any_key();
	  }
	  for(block=0;block<BLOCKS;block++)
	  {
		  for(k=0;k<64;k++)
		  {
			  bts[k] = 0;
		  }
		  int X = Blocks[block].X*4;
		  int Y = Blocks[block].Y*4;
		  LCD_Write64bytes(X,Y,bts);
	  }
	  
  }
  //~ 
  int adr ;
  for( adr=0x4000;adr<=0xffff;adr++)
  {
	  poke(adr,(adr>>3) ^0x55);
  }
  for( adr=0x4000;adr<=0xffff;adr++)
  {
	  poke(adr,((adr+100)>>3) ^0x55);
  }
  int  flag=1;
  int stop = -1;
  for( adr=0x4000;adr<=0xffff;adr++)
  {
	  uint8_t rnum = ((adr+100)>>3)^0x55;
	  uint8_t tnum = peek(adr);
	  if(rnum!=tnum&&stop<0)
	  {
		flag = 0; 
		stop = adr;
	  }
  }
  for( adr=0x4000;adr<=0xffff;adr++)
  {
	  poke(adr,0);
  }
  //~ LCD_Draw_Text(printNum16(flag),10,10, GREEN, 2, BLACK);
  LCD_Draw_Text(flag?"OK":"Memory Error",10,10, GREEN, 2, BLACK);
  LCD_Draw_Text(printNum16(stop),10,30, GREEN, 2, BLACK);
  if(flag)
  {
	HAL_Delay(100);
  }
  else
  {
	HAL_Delay(1000);
	wait_any_key();
  }
}

void readCard()
{
	//	
	//~ static int inited=0;
	//~ if(!inited)
	//~ {
	  if(FATFS_LinkDriver(&SD_Driver, SD_Path) == 0)
	  {
	    /* Initialize the SD mounted on adafruit 1.8" TFT shield */
	    if(BSP_SD_Init() != MSD_OK)
	    {
		//~ LCD_Draw_Text("BS_FAIL",100,60, LG, 1,BLACK);    
		z80_reset(1);
		return ;
	    }  
	    
	    /* Check the mounted device */
	    if(f_mount(&SD_FatFs,SD_Path, 0) != FR_OK)
	    {
		//~ LCD_Draw_Text("~MOUNT",100,60, LG, 1,BLACK);    
	      //~ TFT_DisplayErrorMessage(FATFS_NOT_MOUNTED);
		z80_reset(1);
		return ;
	    }  
	  }
	  else
	  {
		z80_reset(1);
		return ;
	  }
	//~ }
	//~ inited =1;

	//~ HAL_Delay(1000);
  //~ MX_FATFS_Init();
	clearFullScreen();
	FRESULT res;
	FILINFO MyFileInfo;
	DIR MyDirectory;
	FIL MyFile;
	//~ int num = FATFS_GetAttachedDriversNbr();
	//~ LCD_Draw_Text("drive:",10,0, GREEN, 1, BLACK);
	//~ LCD_Draw_Text(printNum(num),10,CHAR_HEIGHT, GREEN, 1, BLACK);
	int numFiles = 0;
	int chooseNum = 0;
	int pass;
	for(pass=0;pass<2;pass++)
	{
		if(pass)
		{
			// get Icon choose & calc number
			int32_t Coordinates[2];
			Coordinates[0] = -1;
			if(numFiles==0)
			{
				z80_reset(1);
				return ;
			}
			while(Coordinates[0]==-1)
			{
				while(!TP_Touchpad_Pressed())
				{
					//
				}
				TP_Read_Coordinates(Coordinates);
				//~ LCD_Draw_Text(printNum16(Coordinates[0]),10,140, GREEN, 2, BLACK);
				//~ LCD_Draw_Text(printNum16(Coordinates[1]),10,140+20, GREEN, 2, BLACK);
				
			}
			paintCross(Coordinates[0],Coordinates[1],8,YELLOW);
			HAL_Delay(4000);
			chooseNum = (Coordinates[1]/48)*5+(Coordinates[0]/64);
			numFiles = 0;
			//~ LCD_Draw_Text(printNum(chooseNum),10,130, GREEN, 2, BLACK);
			//~ HAL_Delay(4000);
			
		}
	res = f_opendir(&MyDirectory,SD_Path);
	  
	  if(res == FR_OK)
	  {
	    for (;;)
	    {
	      res = f_readdir(&MyDirectory, &MyFileInfo);
	      if(res != FR_OK || MyFileInfo.fname[0] == 0) 
		break;
	      //~ if(MyFileInfo.fname[0] == '.') 
		//~ continue;
	      //~ if(numFiles<LCD_getHeight()/CHAR_HEIGHT-2)
	      {
		      //~ int cl = BLUE;
		      if(strncmp(MyFileInfo.fname,"SPEC",4)==0)
		      {
			      //~ cl= GREEN;
			      if(f_open(&MyFile,MyFileInfo.fname, FA_READ)==FR_OK)
			      {
				     UINT BytesRead;
				     if(pass==0)
				     {		
	//~ ofs.write((const char*)&reg,sizeof(reg));
	//~ ofs.write((const char*)&reg_,sizeof(reg_));
	//~ ofs.write((const char*)&IM,sizeof(IM));
	//~ ofs.write((const char*)&IFF1,sizeof(IFF1));
	//~ ofs.write((const char*)&IFF2,sizeof(IFF2));
	//~ ofs.write((const char*)&halt,sizeof(halt));
		//~ ofs.write((const char*)&RAM,sizeof(RAM));
					     //
					     
					     //read icon to screen;
					     int x = numFiles%5;
					     int yy = numFiles/5;
					     int k;
					     int y;
					     u8 bt[32*3];
					     for(y=0;y<24;y++)
					     {
						 f_read(&MyFile,&bt[0],32*3,&BytesRead);
						 //  copy to screen  position  
						 for(k=0;k<32;k++)
						{		
							LCD_FullRect6(x*64+k*2,(yy*24+y)*2,&bt[k*3],&bt[k*3],2,2); 
						}
					     }
					      numFiles++;
				      }
				      else
				      {
					      if(numFiles>=chooseNum)
					      {
						      clearFullScreen();
						      f_lseek(&MyFile,32*3*24);
						      f_read(&MyFile,&reg,sizeof(reg),&BytesRead);
						      f_read(&MyFile,&reg_,sizeof(reg_),&BytesRead);
						      f_read(&MyFile,&IM,sizeof(IM),&BytesRead);
						      f_read(&MyFile,&IFF1,sizeof(IFF1),&BytesRead);
						      f_read(&MyFile,&IFF2,sizeof(IFF2),&BytesRead);
						      f_read(&MyFile,&halt,sizeof(halt),&BytesRead);
						      uint32_t adr;
					      
						      for( adr=0x4000;adr<=0xffff;adr+=0x40)
						      {		
							  u8 bt[0x40];
							  f_read(&MyFile,&bt[0],0x40,&BytesRead);
							      int k;
							 for(k=0;k<0x40;k++)
							{		
								poke(adr+k,bt[k]);
							}
							//~ LCD_Draw_Text(printNum16(adr),150,80, GREEN, 2,BLACK);
						      }
						      // 
						      f_close(&MyFile);
						      f_closedir(&MyDirectory);
						      f_mount(NULL,SD_Path, 0);
						      FATFS_UnLinkDriver(SD_Path);
						      return;
					      }
					      numFiles++;
				      }
				f_close(&MyFile);
			      }
			      else
			      {
				      //~ cl= RED;
			      }
			      
		      }
	      }
	      //~ numFiles++;
	      //~ HAL_Delay(10);
            }
	    f_closedir(&MyDirectory);
	}
	else if(res==FR_NO_FILESYSTEM)
	{
		//~ LCD_Draw_Text("format?",10,130, GREEN, 2, BLACK);
	}
	else
	{
		//~ LCD_Draw_Text("open fail",10,130, GREEN, 2, BLACK);
	}
	}
      f_mount(NULL,SD_Path, 0);
      FATFS_UnLinkDriver(SD_Path);
		z80_reset(1);
		return ;
      	
}
void TP_init_default();
void minit()
{

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  LCD_init(); 
  //~ LCD_setOrientation(ORIENTATION_PORTRAIT);
  LCD_setOrientation(ORIENTATION_LANDSCAPE);
  
  LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), BLACK);
  //~ LCD_Draw_Text("Hello",10,10 , GREEN, 2, BLUE);
  //~ HAL_Delay(100);
  //~ LCD_Draw_Text("From Dima ",10,10 , GREEN, 2, BLUE);
  //~ HAL_Delay(100);
  //~ LCD_Draw_Text("Samsonov  ",10,10 , GREEN, 2, BLUE);
  //~ HAL_Delay(100);
  //~ reCalibrateTouch(0);
	//~ reCalibrateTouch(1);
  //~ touchSetting();
  TP_init_default();
#if 0  
  {
  int k;
  int flag = 1;
for(k=0;k<256;k++)
{
	uint8_t res   = (1-__builtin_parity(k))*0x04;
	uint8_t res1 = parity_table[k];
	if(res!=res1)
	{
		flag =0;
		//~ std::cout<<hex<<"k = "<<(int)k <<" res = "<<(int)res <<" res1 = "<<(int)res1<<"\n"; 
	}
	
}
	LCD_Draw_Text(flag?"OK":"Memory Error",10,10, GREEN, 2, BLACK);
	HAL_Delay(10000);
}
#endif
#if 1  
	  clearFullScreen();
#if 0
  uint8_t result = BSP_SD_Init();
  //~ uint8_t result = sd_initialize(5);
  if(!result)
  {
	  LCD_Draw_Text("Card found",10,10, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNum16_2(result),10,30, GREEN, 2, BLUE);
	  
	  SD_CardInfo CardInfo;
	  
	  uint8_t result1 = BSP_SD_GetCardInfo(&CardInfo);
	  
	  LCD_Draw_Text(printNumU(result1),10,50, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNumU(CardInfo.CardCapacity),10,70, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNumU(CardInfo.CardBlockSize),10,90, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNumU(CardInfo.LogBlockNbr),10,110, GREEN, 2, BLACK);
	  LCD_Draw_Text(printNumU(CardInfo.LogBlockSize),10,130, GREEN, 2, BLACK);
	  result = BSP_SD_GetCardState();
	  LCD_Draw_Text(printNum16_2(result),10,150, GREEN, 2, BLACK);
	  
  }
  else 
  {
	  LCD_Draw_Text("Card not found",10,30, GREEN, 2, BLACK);
	  HAL_Delay(1000);
  }
#endif  
  
  
	clearFullScreen();
  
	initBlocksAndLines();
  
	//~ memory_test();	
	z80_reset(1);
	missSaveMemory = 0;
	missReadMemory = 0;
	readCard() ; 
	//~ wait_any_key();
  //~ HAL_Delay(10000);
#endif 
       //~ clearFullScreen();
#if 0	
	LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), color);
	int32_t Coordinates[2];
	RTC_DateTypeDef Date;
	int oldSec = -1;
	int oldMin = -1;
	int oldDay = -1;
	 
	int bW= LCD_getWidth()/8;
	int YY = LCD_getHeight()-CHAR_HEIGHT*3-1;
	addKey("H+",2,0,YY,3);
	addKey("H-"  ,3,bW,YY,3);
	addKey("M+",4,bW*2,YY,3);
	addKey("M-"  ,5,bW*3,YY,3);
	addKey("SC"   ,6,bW*4,YY,3);
	addKey("CL"   ,7,bW*5,YY,3);
	addKey("CS"   ,8,bW*6,YY,3);
	addKey("SS"   ,9,bW*7,YY,3);
#define CLOCK 0  
#define SCOPE 1  
#define CARD   2  
#define SPEED 3  
	 int state = CLOCK;
	 LCD_idle(1) ;
	 paintKeys();
	 int bRepaint = 0;
#endif	 
	setAttr();	
}
int flagg = 1;
void LCD_Write8x8line(uint16_t x1, uint16_t y1,uint8_t * adress) ;
void LCD_FullRect3(uint16_t x1, uint16_t y1,uint8_t * adress,uint16_t w,uint16_t h) ;
int32_t  tickperv =-1000;
void mloop()
{
	uint32_t  tickstart = HAL_GetTick();
	//~ tstate_summ = 0;
	//~ for(k=0;k<20000;k++)
	if(!flagg)
	{
		for(tstates=0;tstates<69888u;)
		{ 
			z80_run();
		}
	}
	else
	{
		setAttr();	
	}
	uint32_t tickCurrent =  HAL_GetTick();
	while(HAL_GetTick()-tickstart<20)
	{
		HAL_Delay(1);
	}
		
	flagg =0;
	
	uint32_t time_is1 = (tickCurrent - tickstart);
	if(TP_Touchpad_Pressed())
	{
		flagg = 1;
		readCard();
	}
	//~ char rb[0x10];
	//~ sprintf(rb,"%03x",opcode);
	if(HAL_GetTick()-tickperv>=40)
	{
				tickperv = HAL_GetTick();
		
				HAL_SPI_DeInit(&hspi1);	
				MX_SPI1_Init(1);
				SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
				SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
		
				//~ HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD);
				static uint16_t old_border =0xffff;
				if(old_border!=(border&0x7))
				{
					old_border = border&0x7;
					const uint16_t yScr = (240-192)/2;
					const uint16_t xScr = (320-256)/2;
					uint8_t buff[3];
					buff[0] = 0xd7*(!!(border&2));
					buff[1] = 0xd7*(!!(border&4));
					buff[2] = 0xd7*(!!(border&1));
					LCD_FullRect3(xScr-4,yScr-4,buff,4,192+8) ;
					LCD_FullRect3(xScr+256,yScr-4,buff,4,192+8) ;
					LCD_FullRect3(xScr-4,yScr-4,buff,256+8,4) ;
					LCD_FullRect3(xScr-4,yScr+192,buff,256+8,4) ;
				}
				
				// x tile_ofs = x (0,32)
				// y tile_ofs 
				int x,yb;
				for( yb=0;yb<24;yb++)
				{
					int xb;
					for(xb=0;xb<32;xb++)
					{
						int tileAddr = xb+yb*32;
						if(ATTR_RAM_MOD[tileAddr>>3] & (1<<(tileAddr&0x3)))
						{
							//~ ATTR_RAM_MOD[tileAddr>>3] &= 0xff-(1<<(tileAddr&0x3));
							uint8_t attr = ATTR_RAM[tileAddr];
							uint8_t Br = !!(attr&64);
							uint8_t scale = (Br?0xff:0xd7);
							
							int Fl = !!(attr&128);
							if(Fl&&(tickCurrent/1000)&1)
							{	
								scale = (Br?0xd7:0xff);
							}
							uint8_t RInc= scale*!!(attr&2);
							uint8_t GInc= scale*!!(attr&4);
							uint8_t BInc= scale*!!(attr&1);

							uint8_t Rpap= scale*!!(attr&16);
							uint8_t Gpap= scale*!!(attr&32);
							uint8_t Bpap= scale*!!(attr&8);
							//~ ATTR_RAM_MOD[tileAddr>>3] &= ~(1<<(tileAddr&0x3));
							uint8_t buff[8][24];
							int yt;
							int xScr = xb*8+(320-256)/2;
							int yScr = yb*8+(240-192)/2;
							for(yt=0;yt<8;yt++)
							{
								int y = yt+yb*8;
								//~ uint8_t lineColor[32];
								uint16_t vr = ((y<<8)&0x0700)|((y<<2)&0xe0)|((y<<5)&0x1800);
								uint8_t   val  = VIDEO_RAM[vr+xb];
								int bit;
								for(bit=0;bit<8;bit++)
								{
									
									
									int bt          =((val>>(7-bit))&1);
									buff[yt][bit*3+0] = bt?(RInc):(Rpap);
									buff[yt][bit*3+1] = bt?(GInc):(Gpap);
									buff[yt][bit*3+2] = bt?(BInc):(Bpap);
								}
								//~ LCD_Write8line(xScr,yScr,buff) ;
							}
							LCD_Write8x8line(xScr,yScr,&buff[0][0]) ;
						}
					}
				}
				
		//~ MX_SPI1_Init(0);
		//~ SPIx_Error2 ();
		SPIx_Error1 ();
		SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI

	clearAttr();	
	}
	screen_IRQ = 1;
	//~ LCD_Draw_Text(printNum(time_is1),100,60, BLACK, 2,GREEN);
	//~ LCD_Draw_Text(printNum16(timeTick),100,80, BLACK, 2,GREEN);
	//~ LCD_Draw_Text(printNum16(missSaveMemory),100,100, BLACK, 2,GREEN);
	//~ LCD_Draw_Text(printNum16(missReadMemory),100,120, BLACK, 2,GREEN);
	missSaveMemory = 0;
	missReadMemory = 0;
}
