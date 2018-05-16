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
extern int32_t checkerror;
extern int32_t checkdeinit;
uint16_t 		border;
extern int32_t tstates;
extern int32_t interrupts_enabled_at;
//~ extern u8 	opcode;
extern u8 	screen_IRQ;
extern u8 	IM;

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
	u8 input=0xff;
	if ((port&0x00FF)==0xFE)//перехват порта 0xFE
	{
		uint16_t res =((KEYB_0_GPIO_Port->IDR>>3)&0b1111111);
		if(!(port&(1<<11)))
		{
			if(!(res&0x4))
			{
				input &= ~(1u<<4);
			}
		}
		if(!(port&(1<<12)))
		{
			if(!(res&0x1))
			{
				input &= ~(1u<<4);
			}
			if(!(res&0x10))
			{
				input &= ~(1u<<3);
			}
			if(!(res&0x8))
			{
				input &= ~(1u<<2);
			}
			if(!(res&0x40))
			{
				input &= ~(1u<<1);
			}
			if(!(res&0x20))
			{
				input &= ~(1u<<0);
			}
		}
		if(!(port&(1<<15)))
		{
				if(!(res&0x2)) //space
				{
					input &= ~(1u<<0);
				}
		}
		//~ if(res&0x4==0)	// left 5
		//~ if(res&0x8==0)	// rigth 8
		//~ if(res&0x10==0)	// up  7
		//~ if(res&0x1==0)	// down 6
		//~ if(res&0x20==0)	// zero  0
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
#define EXIST 		0x2000 
#define MODIFIED 	0x4000 
//~ #define TO_DISPLAY	0x800 
#define BLOCKS ((0x10000-0x5B00)/64)
struct block
{
	uint8_t  X;  
	uint8_t  Y; 
	uint16_t  flag_line; 
	//~ uint8_t  flags; // 0x200 - exist mask  0x400 modified by write 	//~ uint8_t  line;  // line - pointer
}  Blocks[BLOCKS];

#define NUM_LINES (100)

struct cacheLinePool
{
	uint8_t    cacheLine[64];
	uint16_t  currentBlockNumber;
	int32_t  lastTimeTick;
}  Lines[NUM_LINES];

int32_t  timeTick = 0;
int16_t  missSaveMemory = 0;
int16_t  missReadMemory = 0;

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

inline static int insizeXY(int x,int y)
{
	return (x>=LX&&x<LX+SW&&y>=LY&&y<LY+SH);
}

void initBlocksAndLines()
{
	
	uint16_t k=0;
	// all screen is  320/4*240/4 blocs;
	// allocated to spessi screen is (256+8)/4*(192)/4
	uint16_t cnt = 0;
	int y,x,yy,xx;
	for(y=0;y<HH;y+=BY)
	{
		for(x=0;x<WW;x+=BX)
		{
			uint16_t free = 1;
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
			if(free)
			{
				Blocks[cnt].X = x;
				Blocks[cnt].Y = y;
				Blocks[cnt].flag_line = 0; //not exist
				cnt++;
			}
			if(cnt==BLOCKS)
			{
				goto  ENOU;
			}				
		}
		
	}
ENOU:
	
	//~ LCD_Draw_Text(printNum(cnt),4,LCD_getHeight()/2, YELLOW, 4, BLACK);   
	//~ HAL_Delay(500);
	for(k=0;k<NUM_LINES;k++)
	{
		Lines[k].currentBlockNumber = k;
		Lines[k].lastTimeTick = 0;
		Blocks[k].flag_line           = EXIST | k;
	}
}


int  findOldestLine()
{
		// find oldest line for commit
	int   oldestLineIndex = 0;
	int32_t timediff       = 0;
	int k;
	for(k=0;k<NUM_LINES;k++)
	{
		int32_t diffval = timeTick-Lines[k].lastTimeTick;
		if(diffval>timediff)
		{
			timediff = diffval;
			oldestLineIndex = k;
		}
	}
	return oldestLineIndex;
}

void writeCache64bIfmodified(uint16_t blockNumber,uint8_t * data)
{
	if(Blocks[blockNumber].flag_line&MODIFIED)
	{
		uint16_t X = (Blocks[blockNumber].X)*4;
		uint16_t Y = (Blocks[blockNumber].Y)*4;
		LCD_Write64bytes(X,Y,data);
		missSaveMemory++;
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
	line->lastTimeTick = timeTick;
	line->cacheLine[adress&0x3f] = data;
	bl->flag_line|=MODIFIED;//|TO_DISPLAY;
}

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
	  
	  LCD_Draw_Text(flag?"OK":"Memory Error",80,130, GREEN, 1, BLACK);
	  LCD_Draw_Text(printNum16(checkerror),80,140, BLACK, 1,GREEN);
	  LCD_Draw_Text(printNum16(blockErr),80,150, GREEN, 1, BLACK);
	  //~ if(flag)
	  //~ {
		//~ HAL_Delay(100);
	  //~ }
	  //~ else
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
  LCD_Draw_Text(flag?"OK":"Memory Error",80,160, GREEN, 1, BLACK);
  LCD_Draw_Text(printNum16(stop),80,170, GREEN, 1, BLACK);
  LCD_Draw_Text(printNum16(checkerror),80,180, BLACK, 1,GREEN);
  //~ if(flag)
  //~ {
	//~ HAL_Delay(100);
  //~ }
  //~ else
  {
	HAL_Delay(1000);
	wait_any_key();
  }
}
FATFS SD_FatFs;  /* File system object for SD card logical drive */
char SD_Path[4]; /* SD card logical drive path */

int readCard()
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
		//~ z80_reset(1);
		return 0;
	    }  
	    
	    /* Check the mounted device */
	    if(f_mount(&SD_FatFs,SD_Path, 0) != FR_OK)
	    {
		//~ LCD_Draw_Text("~MOUNT",100,60, LG, 1,BLACK);    
	      //~ TFT_DisplayErrorMessage(FATFS_NOT_MOUNTED);
		//~ z80_reset(1);
		return 0;
	    }  
	  }
	  else
	  {
		//~ z80_reset(1);
		return 0;
	  }
	//~ }
	//~ inited =1;

	//~ HAL_Delay(1000);
  //~ MX_FATFS_Init();
	clearFullScreen();
	FRESULT 	res;
	FILINFO 	MyFileInfo;
	DIR 		MyDirectory;
	FIL 		MyFile;
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
				return 0;
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
			//~ HAL_Delay(4000);
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
	      //~ if(numFiles<LCD_getHeight()/CHAR_HEIGHT-2)
	      {
		      if(strncmp(MyFileInfo.fname,"SPEC",4)==0)
		      {
			      if(f_open(&MyFile,MyFileInfo.fname, FA_READ)==FR_OK)
			      {
					UINT BytesRead;
					u8 bt[0x100];
					int y,k;
					if(pass==0)
					{		
					     //read icon to screen;
					     int x = numFiles%5;
					     int yy = numFiles/5;
					     //~ u8 bt[32*3];
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
						      //~ f_lseek(&MyFile,32*3*24);
						      for(y=0;y<24;y++)
						      {
							      f_read(&MyFile,&bt[0],32*3,&BytesRead);
						      }
						      f_read(&MyFile,&reg,sizeof(reg),&BytesRead);
						      f_read(&MyFile,&reg_,sizeof(reg_),&BytesRead);
						      f_read(&MyFile,&IM,sizeof(IM),&BytesRead);
						      f_read(&MyFile,&IFF1,sizeof(IFF1),&BytesRead);
						      f_read(&MyFile,&IFF2,sizeof(IFF2),&BytesRead);
						      f_read(&MyFile,&halt,sizeof(halt),&BytesRead);
						      for( y=0x4000;y<=0xffff;y+=0x100)
						      {		
								f_read(&MyFile,&bt[0],0x100,&BytesRead);
								 for(k=0;k<0x100;k++)
								{		
									poke(y+k,bt[k]);
								}
						      }
						      checkerror = 0;
						      // 
						      f_close(&MyFile);
						      f_closedir(&MyDirectory);
						      f_mount(NULL,SD_Path, 0);
						      FATFS_UnLinkDriver(SD_Path);
						      return 1;
					      }
					      numFiles++;
				      }
				f_close(&MyFile);
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
		//~ z80_reset(1);
	return  0;
      	
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
	TP_init_default();

	clearFullScreen();
  
	initBlocksAndLines();
  
	memory_test();	
	z80_reset(1);
	missSaveMemory = 0;
	missReadMemory = 0;
	if(!readCard())
	{
		clearFullScreen();
		z80_reset(1);
	}
	checkerror = 0; 
	setAttr();	
}
int flagg = 1;
void LCD_Write8x8line(uint16_t x1, uint16_t y1,uint8_t * adress) ;
void LCD_FullRect3(uint16_t x1, uint16_t y1,uint8_t * adress,uint16_t w,uint16_t h) ;
int32_t  tickperv =-1000;
void mloop()
{
	int32_t  tickstart = HAL_GetTick();
	//~ tstate_summ = 0;
	//~ for(k=0;k<20000;k++)
	if(!flagg)
	{
		//~ LCD_Draw_Text("A",80,60, BLACK, 1,GREEN);
		//~ HAL_SPI_DeInit(&hspi1);	
		//~ MX_SPI1_Init(1);
		//~ SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		//~ SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
		
		for(tstates=0;tstates<69888u;)
		{ 
			z80_run();
		}
		//~ LCD_Draw_Text("B",80,60, BLACK, 1,GREEN);
	}
	else
	{
		setAttr();	
	}
	uint32_t tickCurrent =  HAL_GetTick();
	//~ LCD_Draw_Text("C",80,60, BLACK, 1,GREEN);
	while(HAL_GetTick()-tickstart<20)
	{
		HAL_Delay(1);
	}
		
	flagg =0;
	
	uint32_t time_is1 = (tickCurrent - tickstart);
	//~ LCD_Draw_Text("D",80,60, BLACK, 1,GREEN);
	if(TP_Touchpad_Pressed())
	{
		flagg = 1;
		if(!readCard())
		{
			clearFullScreen();
			z80_reset(1);
		}
	}
	//~ char rb[0x10];
	//~ sprintf(rb,"%03x",opcode);
	//~ LCD_Draw_Text("E",80,60, BLACK, 1,GREEN);
	if(HAL_GetTick()-tickperv>=40)
	{
				tickperv = HAL_GetTick();
		
#if 0				
				HAL_SPI_DeInit(&hspi1);	
				MX_SPI1_Init(1);
				SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
				SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
#endif		
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
#if 0				
		SPIx_Error1 ();
		SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
		SPIx_Error1 ();
		SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
#endif				
		
	clearAttr();	
	}
	//~ LCD_Draw_Text("F",80,60, BLACK, 1,GREEN);
	screen_IRQ = 1;
	//~ IFF1 = 1;
	//~ uint16_t res =((KEYB_0_GPIO_Port->IDR>>3)&0b1111111)|0x1000;
	//~ {
		//~ int stable[] = {KEYB_0_Pin,KEYB_1_Pin,KEYB_2_Pin,KEYB_3_Pin,KEYB_4_Pin,KEYB_5_Pin,KEYB_6_Pin};
		//~ int k; 
		//~ for(k=0;k<7;k++)
		//~ {
			//~ res<<=1;
			//~ res |= HAL_GPIO_ReadPin(KEYB_0_GPIO_Port,stable[k]);
			
		//~ }
	//~ }
	
	LCD_Draw_Text(printNum16(time_is1),80,70, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(timeTick),80,80, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(missSaveMemory),80,90, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(missReadMemory),80,100, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(PC),80,110, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(halt),80,120, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(tstates),80,130, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(interrupts_enabled_at),80,140, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(IFF1),80,150, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(IM),80,160, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(HAL_GetTick()),80,170, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(checkerror),80,180, BLACK, 1,GREEN);
	LCD_Draw_Text(printNum16(checkdeinit),80,190, BLACK, 1,GREEN);
	missSaveMemory = 0;
	missReadMemory = 0;
}
