#include "stm32f4xx.h"
int32_t tstates = 0;
int32_t interrupts_enabled_at;

#include "z80.h"
#include <stdio.h>
/*include z80 registr*/
/*основная группа регистров*/
 ZReg reg;

/*теневая группа регистров*/
ZReg_Shadow reg_;

/*флаги прерываний*/
u8 IFF1;
u8 IFF2;
u8 IM;
u8 halt;

u8 screen_IRQ=0;


/*объединение беззнаковой и знаковой переменной для определения смещения*/
union
{
	u8 u;
	s8 s;
}d;



#include "tables.c"

/*include opcodes*/


void z80_reset( int hard_reset )
{
	/*
		int i,j,k;
	uint8_t parity;
	
  for(i=0;i<0x100;i++) {
    sz53_table[i]= i & ( FLAG_3 | FLAG_5 | FLAG_S );
	if(i==0)
	{
		sz53_table[i] = 0x40;
	}
	//~ if(sz53_table[i]!=sz53_table_b[i])  
	//~ {
		//~ printf("sz53_table %x, %x, %x \n",i,(int)sz53_table[i],(int)sz53_table_b[i]);
	//~ }
    j=i; parity=0;
    for(k=0;k<8;k++) { parity ^= j & 1; j >>=1; }
    uint8_t parity_table_i = ( parity ? 0 : FLAG_P );
    sz53p_table[i] = sz53_table[i] | parity_table_i;
	//~ if(sz53p_table[i]!=sz53p_table_b[i])  
	//~ {
		//~ printf(" sz53p_table %x, %x, %x \n",i,(int)sz53p_table[i],(int)sz53p_table_b[i]);
	//~ }
  }

	*/
	
  AF =AF_=0xffff;
  I=R=R7=0;
  PC=0;
  SP=0xffff;
  IFF1=IFF2=IM=0;
  halt=0;
  if( hard_reset ) {
    BC =DE =HL =0;
    BC_=DE_=HL_=0;
    IX=IY=0;
    MEMPTR=0;
  }
      screen_IRQ = 0;
      interrupts_enabled_at = -6;
	
	
  //~ z80.iff2_read=0;	
	//~ AF=0;
	//~ AF=0;
	//~ BC=0;
	//~ DE=0;
	//~ HL=0;
	//~ IX=0;
	//~ IY=0;
	//~ SP=0;
	//~ PC=0;
	//~ IFF1=IFF2=0;
	//~ IM=0;
	//~ MEMPTR=0;
  
	return;
}
//~ u16 i;
#define EMPTY ;

void z80_run(void)
{
u8 temp8;
u16 temp16;

u8 opcode;

u16 exx_temp;
u32 add_temp;
u32 sub_temp;
u16 cp_temp;
u8 bo_temp;

u8 in_temp;
u8 neg_temp;
//~ u16 daa_temp;
u8 rot_temp;

u8 lookup;

u8 n;
u16 nn;


	if ((screen_IRQ==1)&&(IFF1==1)&&(tstates > interrupts_enabled_at))
	{
		if(IM==1||IM==0)
		{
			IFF1=0;
			IFF2=1;
			if(halt)
			{
				PC++;
				halt = 0;
			}
			screen_IRQ=0;
			RST(0x38);
			
			//~ tstates+=m_cycle;
		}
		else	if(IM==2)
		{
			IFF1=0;
			IFF2=1;
			uint16_t addr = (((uint16_t)I)<<8)|0xff;
			uint16_t jmp_addr=peek16(addr);
			//~ printf("addr = %4x %4x\n",addr,jmp_addr);
			if(halt)
			{
				PC++;
				halt = 0;
			}
			screen_IRQ=0;
			RST(jmp_addr);
			//~ tstates+=m_cycle;
		}
		return;	
	}
//~ CONT:	
	//~ if (halt==0)
u16 m_cycle = 0;
u8   prefix     = 0;	
	opcode=NEXT_BYTE;
	R++;
#include "opcode_base.c"
	if (prefix==0xCB)
	{
		opcode=NEXT_BYTE;
		R++;
#include "opcode_cb.c"
		m_cycle+=4+4;
	}
	else if (prefix==0xED)
	{
		opcode=NEXT_BYTE;
		R++;
#include "opcode_ed.c"
		m_cycle+=4;
	}
	else if (prefix==0xDD ||  prefix==0xFD)
	{
		if(prefix==0xFD)
		{
			u16 tempR = IX;
			IX = IY;
			IY = tempR;
		}
		opcode=NEXT_BYTE;
		R++;
		if (opcode==0xCB)
		{
			d.u=NEXT_BYTE;
			opcode=NEXT_BYTE;
			MEMPTR=(IX+d.s);
			temp8=READ_BYTE(IX+d.s);
#include "opcode_ddcb.c"
			WRITE_BYTE(IX+d.s, temp8);
			m_cycle+=4+19;
		}
		else
		{
#include "opcode_dd.c"
			m_cycle+=4;
		}
		if(prefix==0xFD)
		{
			u16 tempR = IX;
			IX = IY;
			IY = tempR;
		}
	}
	tstates+=m_cycle;
}

