#include <iostream>
#include <stdint.h>
#include <fstream>
#include "generateBlockInd.h"

static int insizeXY(int x,int y)
{
	return (x>=LX&&x<LX+SW&&y>=LY&&y<LY+SH);
}

int main()
{
	uint16_t k=0;
	// all screen is  320/4*240/4 blocs;
	// allocated to spessi screen is (256+8)/4*(192)/4
	uint16_t cnt = 0;
	int y,x,yy,xx;
	std::ofstream ofs("../Inc/blocks.h");
	ofs<<"const struct blockR\n{\n uint8_t  X;\n uint8_t  Y;\n }\n BlocksR[BLOCKS] = { \n ";

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
				if(cnt==0)
				{
					ofs<<"{"<<x<<","<<y<<"}\n";
				}
				else
				{
					ofs<<",{"<<x<<","<<y<<"}\n";
				}
				//~ Blocks[cnt].X = x;
				//~ Blocks[cnt].Y = y;
				//~ Blocks[cnt].flag_line = 0; //not exist
				cnt++;
			}
			if(cnt==BLOCKS)
			{
				goto  ENOU;
			}				
		}
		
	}
ENOU:
	ofs<<"};\n";
	return 0;
}