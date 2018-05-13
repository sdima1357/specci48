#include "main.h"
#include "stm32f1xx_hal.h"
//~ #include "gpio.h"
//~ #include "spi.h"

#define CMD_RDY             			0X90
#define CMD_RDX             			0XD0
//RETURN VALUES FOR TP_Touchpad_Pressed 
#define TOUCHPAD_NOT_PRESSED			0
#define TOUCHPAD_PRESSED					1

//RETURN VALUES FOR TP_Read_Coordinates
#define TOUCHPAD_DATA_OK					1
#define TOUCHPAD_DATA_NOISY				0
//~ #define TOUCH1_MOSI_Pin 		GPIO_PIN_7
//~ #define TOUCH1_MISO_Pin 		GPIO_PIN_5
//~ #define TOUCH1_CLOCK_Pin 		GPIO_PIN_6 
//~ #define TOUCH1_CLOCK_GPIO_Port 	GPIOA
//~ #define TOUCH1_MISO_GPIO_Port 	GPIOA
//~ #define TOUCH1_MOSI_GPIO_Port 	GPIOA
extern SPI_HandleTypeDef hspi1;
void  SPIx_Error1 (void);
 void MX_SPI1_Init(int);
 //~ void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle);
//In order to increase accuracy of location reads library samples
//NO_OF_POSITION_SAMPLES numbers of locations and averages them
//If library runs too slow decrease NO_OF_POSITION_SAMPLES, but
//expect inreasingly noisy or incorrect locations returned

#define NO_OF_POSITION_SAMPLES	 	1000

sTouchCalibration  TouchCalibration;

sTouchCalibration* getCalibr()
{
	return &TouchCalibration;
}
//Internal Touchpad command, do not call directly
static uint16_t TP_Read(void)
{
    uint8_t i = 16;
    uint16_t value = 0;

    while(i > 0x00)
    {
        value <<= 1;

				HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_RESET);
			
        if(HAL_GPIO_ReadPin(TOUCH1_MISO_GPIO_Port, TOUCH1_MISO_Pin) != 0)
        {
            value++;
        }

        i--;
    };

    return value;
}

//Internal Touchpad command, do not call directly
static void TP_Write(uint8_t value)
{
    uint8_t i = 0x08;

		HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_RESET);	
	
    while(i > 0)
    {
        if((value & 0x80) != 0x00)
        {
						HAL_GPIO_WritePin(TOUCH1_MOSI_GPIO_Port, TOUCH1_MOSI_Pin, GPIO_PIN_SET);
        }
        else
        {
						HAL_GPIO_WritePin(TOUCH1_MOSI_GPIO_Port, TOUCH1_MOSI_Pin, GPIO_PIN_RESET);
        }

        value <<= 1;
				HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_RESET);        
        i--;
    };
}

//~ void SD_IO_Init(void);

//Read coordinates of touchscreen press. Position[0] = X, Position[1] = Y
static const uint32_t TP_def_arr[]=
{
	0x38209b00,
	0xbbcfdf3e,
	0x43ba7824,
	0xbb9397b4,
	0x38ec4af0,
	0x437b3df1
};

void     TP_init_default()
{
	int X,Y;
	for(Y=0;Y<2;Y++)
	{
		for(X=0;X<3;X++)
		{
			TouchCalibration.Transform[Y][X]= *(float*)&TP_def_arr[Y*3+X];
		}
	}
	
}
uint8_t TP_Read_Coordinates(int32_t Coordinates[2])
{
		uint8_t stat =  TOUCHPAD_DATA_NOISY;
		Coordinates[0] = -1;
		Coordinates[1] = -1;
		HAL_SPI_DeInit(&hspi1);	
	//~ /*
	#if 1
		HAL_GPIO_WritePin(TOUCH_CS_GPIO_Port, TOUCH_CS_Pin, GPIO_PIN_SET);		
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//~ */
	
		HAL_GPIO_WritePin(TOUCH1_CLOCK_GPIO_Port, TOUCH1_CLOCK_Pin, GPIO_PIN_SET);		
		HAL_GPIO_WritePin(TOUCH1_MOSI_GPIO_Port, TOUCH1_MOSI_Pin, GPIO_PIN_SET);		
		

	
	
		uint32_t calculating_x = 0;
		uint32_t calculating_y = 0;
	
		uint32_t samples = NO_OF_POSITION_SAMPLES;
		uint32_t counted_samples = 0;

		HAL_GPIO_WritePin(TOUCH_CS_GPIO_Port, TOUCH_CS_Pin, GPIO_PIN_RESET);
	
    while((samples > 0)&&(HAL_GPIO_ReadPin(TOUCH1_IRQ_GPIO_Port, TOUCH1_IRQ_Pin) == 0))
    {			
        TP_Write(CMD_RDY);

				calculating_y += (uint16_t)TP_Read();

				
	TP_Write(CMD_RDX);
				calculating_x += (uint16_t)TP_Read();
				samples--;
				counted_samples++;
    };
		
		HAL_GPIO_WritePin(TOUCH_CS_GPIO_Port, TOUCH_CS_Pin, GPIO_PIN_SET);

		
		if((counted_samples == NO_OF_POSITION_SAMPLES)&&(HAL_GPIO_ReadPin(TOUCH1_IRQ_GPIO_Port, TOUCH1_IRQ_Pin) == 0))
		{
		
		calculating_x /= counted_samples;
		calculating_y /= counted_samples;
		
		
		//CONVERTING 16bit Value to Screen coordinates
    // 65535/273 = 240!
		// 65535/204 = 320!
		Coordinates[0] = TouchCalibration.Transform[0][0]*calculating_x+TouchCalibration.Transform[0][1]*calculating_y+TouchCalibration.Transform[0][2];
		Coordinates[1] = TouchCalibration.Transform[1][0]*calculating_x+TouchCalibration.Transform[1][1]*calculating_y+TouchCalibration.Transform[1][2];
		
		stat = TOUCHPAD_DATA_OK;			
		}
		else
		{
			Coordinates[0] = -1;
			Coordinates[1] = -1;
		}
#endif		
/*
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
		//~ int8_t dummy=0x0;
		HAL_SPI_TransmitReceive(&hspi1, &dummy,&dummy, 1,100);
		SPIx_Error1 ();
		
*/		
		//~ MX_GPIO_DeInit();
		//~ MX_GPIO_Init();
		MX_SPI1_Init(0);
		//~ SPIx_Error2 ();
		SPIx_Error1 ();
		SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
		SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
		//~ SD_IO_Init();
		return stat;
		//~ HAL_SPI_MspInit(&hspi1);
}

//Check if Touchpad was pressed. Returns TOUCHPAD_PRESSED (1) or TOUCHPAD_NOT_PRESSED (0)
uint8_t TP_Touchpad_Pressed(void)
{
	if(HAL_GPIO_ReadPin(TOUCH1_IRQ_GPIO_Port, TOUCH1_IRQ_Pin) == 0)
	{
		return TOUCHPAD_PRESSED;
	}
	else
	{
		return TOUCHPAD_NOT_PRESSED;
	}
}


