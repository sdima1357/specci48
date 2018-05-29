//~ #include <gpu_util.h>
#include "options.h"
#include <stdlib.h>  
#include <math.h>  
#include <GL/glut.h>
#include <iomanip> 
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int joystickMode = 0;
int kempston = 0;
int ftime = 0;
#define PRINT(x) std::cout<<""<<std::setw(15)<<(x)<<" " #x "\n"
using namespace std;
//~ #include <nvGlutManipulators.h>
//~ #include <widgets.h>
//~ #include <nvTime.h>
//~ #include <namespace.h> 
//~ #include <hiclock.h>
//~ #include <chain.h>
//~ #include <ct/ct_enum.h>
//~ #include <matUtil.h>
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
using namespace std;   
void* handleBase;
uint8_t RAM[0x10000-0x4000];
uint16_t border=0x0000;

extern "C"
{
#include "z80.h"
#include "main_ROM.h"
#include <libspectrum.h>
extern uint8_t IsPressed[][8];
extern int32_t tstates ;
extern int32_t interrupts_enabled_at;
//~ uint8_t	Kempston = 0;
	
void poke(u16 addr, u8 value)
{ 
	if (addr<0x4000)//ROM
	{
	}
	else	RAM[addr-0x4000]=value;//RAM
}

u8 peek(u16 addr)
{
	u8 value;
	if (addr<0x4000)//ROM
	{
		value=ROM[addr];
	}
	else
	{
		value=RAM[addr-0x4000];//RAM
	}
	return value;
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
	if ((port&0x00FF)==31)
	{
		return kempston;
	}
	if ((port&0x00FF)==0xFE)//перехват порта 0xFE
	{
		
		for(int x=0;x<8;x++)
		{
			uint16_t adress = (1u<<x)<<8u;
			if((port&adress)==0)
			{
				for(int y=0;y<5;y++)
				{
					if(IsPressed[y][x])
					{
						input &= ~(1u<<y); //clear bit
					}
				}
			}
		}
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
		border=value&0x07;//D[0-2]цвет бордюра 
	}
}
};

int my80_read(const char* filename)
{
	ifstream ifs(filename,ios::in| ios::binary);
	uint8_t bu8;
	uint16_t bu16;
	int version = 1; 
	int isCompressed = 0;
/*
	IFF1 = libspectrum_snap_iff1(snap) ;
	IFF2 = libspectrum_snap_iff2(snap) ;
	IM = libspectrum_snap_im(snap);	
	halt = libspectrum_snap_halted(snap);
	A    = libspectrum_snap_a(snap);
	F    = libspectrum_snap_f(snap);
	BC  = libspectrum_snap_bc(snap);
	DE  = libspectrum_snap_de(snap);
	HL  = libspectrum_snap_hl(snap);
	//~ L = libspectrum_snap_c(snap);
  	A_    = libspectrum_snap_a_(snap);
	F_    = libspectrum_snap_f_(snap);
	BC_  = libspectrum_snap_bc_(snap);
	DE_  = libspectrum_snap_de_(snap);
	HL_  = libspectrum_snap_hl_(snap);
	IX     = libspectrum_snap_ix(snap);
	IY     = libspectrum_snap_iy(snap);
	SP = libspectrum_snap_sp(snap);
	PC = libspectrum_snap_pc(snap);
	I  = libspectrum_snap_i(snap);
  	R  = libspectrum_snap_r(snap);
	R7 = R;
*/	
	MEMPTR = 0;
	tstates = 11200;
	interrupts_enabled_at = 0;
	cout<<hex;


	ifs.read((char*)&bu8,1);  cout<<hex<<"A="<<int(bu8)<<"\n";   A = bu8;
	ifs.read((char*)&bu8,1);  cout<<hex<<"F="<<int(bu8)<<"\n";   F = bu8;
	ifs.read((char*)&bu16,2);  cout<<hex<<"BC="<<int(bu16)<<"\n"; BC = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"HL="<<int(bu16)<<"\n"; HL = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"PC="<<int(bu16)<<"\n"; PC = bu16;
	
	if(bu16==0) { version = 2; }
	
	ifs.read((char*)&bu16,2);  cout<<hex<<"SP="<<int(bu16)<<"\n"; SP = bu16;
	ifs.read((char*)&bu8,1);  cout<<hex<<"I="<<int(bu8)<<"\n";        I = bu8; 
	ifs.read((char*)&bu8,1);  cout<<hex<<"R="<<int(bu8)<<"\n";       R = bu8;  
	
	ifs.read((char*)&bu8,1);  cout<<hex<<"12 BCCF="<<int(bu8)<<"\n"; R|=(bu8&1)<<7;
	R7= R;
	
	if(bu8&(1<<5))
	{
		isCompressed = 1;
	}
	
	ifs.read((char*)&bu16,2);  cout<<hex<<"DE="<<int(bu16)<<"\n";    DE = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"BC_="<<int(bu16)<<"\n";   BC_ = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"DE_="<<int(bu16)<<"\n";  DE_ = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"HL_="<<int(bu16)<<"\n";  HL_ = bu16;
	
	ifs.read((char*)&bu8,1);  cout<<hex<<"A_="<<int(bu8)<<"\n";         A_ = bu8;
	ifs.read((char*)&bu8,1);  cout<<hex<<"F_="<<int(bu8)<<"\n";         F_ = bu8;
	
	ifs.read((char*)&bu16,2);  cout<<hex<<"IY="<<int(bu16)<<"\n";     IY = bu16;
	ifs.read((char*)&bu16,2);  cout<<hex<<"IX="<<int(bu16)<<"\n";     IX = bu16;	
	
	ifs.read((char*)&bu8,1);  cout<<hex<<"IFF1="<<int(bu8)<<"\n";      IFF1 = bu8;
	ifs.read((char*)&bu8,1);  cout<<hex<<"IFF2="<<int(bu8)<<"\n";	IFF2 = bu8;
	ifs.read((char*)&bu8,1);  cout<<hex<<"29 IM+="<<int(bu8)<<"\n";   IM = bu8&3;
	halt = 0;
	
	if(version>1)
	{
		int b128 = false;
		ifs.read((char*)&bu16,2);  cout<<dec<<"ADD LENGTH="<<int(bu16)<<"\n";
		if(bu16 == 23)
		{
			version = 2;
		}
		else if(bu16 == 54)
		{
			version = 3;
		}
		else if(bu16 == 55)
		{
			version = 4;
		}
		ifs.read((char*)&bu16,2);  cout<<hex<<"PC="<<int(bu16)<<"\n";  PC = bu16;
		ifs.read((char*)&bu8,1);  cout<<hex<<"34="<<int(bu8)<<"\n";      
		if(bu8>1)
		{
			//?128
			b128 = true;
		}
		ifs.read((char*)&bu8,1);  cout<<hex<<"35="<<int(bu8)<<"\n";      
		ifs.read((char*)&bu8,1);  cout<<hex<<"36="<<int(bu8)<<"\n";      
		ifs.read((char*)&bu8,1);  cout<<hex<<"37="<<int(bu8)<<"\n";      
		ifs.read((char*)&bu8,1);  cout<<hex<<"38="<<int(bu8)<<"\n";      
		char sound[0x10];
		ifs.read((char*)sound,0x10);  cout<<hex<<"39[0x10]="<<"\n";   
		if(version>=3)
		{
			ifs.read((char*)&bu16,2);  cout<<hex<<"LOW_T="<<int(bu16)<<"\n";  
			ifs.read((char*)&bu8,1);  cout<<hex<<"HIGH_T="<<int(bu8)<<"\n";  
			ifs.read((char*)&bu8,1);  cout<<hex<<"58="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"59="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"60="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"61="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"62="<<int(bu8)<<"\n";  
			ifs.read((char*)sound,10);  cout<<hex<<"63 keyb[10]="<<"\n";   
			ifs.read((char*)sound,10);  cout<<hex<<"73 ascii[10]="<<"\n";   				
			
			ifs.read((char*)&bu8,1);  cout<<hex<<"83="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"84="<<int(bu8)<<"\n";      
			ifs.read((char*)&bu8,1);  cout<<hex<<"85="<<int(bu8)<<"\n";  
			if(version==4)
			{
				ifs.read((char*)&bu8,1);  cout<<hex<<"86="<<int(bu8)<<"\n";  
			}
		}	
		// read 3 pages
		for(int p=0;p<8;p++)
		{
			ifs.read((char*)&bu16,2);  cout<<hex<<"size="<<int(bu16)<<"\n";  
			ifs.read((char*)&bu8,1);  cout<<hex<<"page="<<int(bu8)<<"\n";  
			int addr = 0x0000;
			if(!b128)
			{
				if(bu8==4)
				{
					addr = 0x8000;
				}
				else if(bu8==5)
				{
					addr = 0xc000;
				}
				else if(bu8==8)
				{
					addr = 0x4000;
				}
			}
			else
			{
				if(bu8==3)
				{
					addr = 0xc000;
				}
				else if(bu8==5)
				{
					addr = 0x8000;
				}
				else if(bu8==8)
				{
					addr = 0x4000;
				}
				
			}
			//~ if(addr!=0)
			{
				if(bu16==0xffff)
				{
					for(int k=0;k<0x4000;k++)
					{
						ifs.read((char*)&bu8,1); 
						poke(addr,bu8);addr++;
					}
				}
				else
				{
					int bytes = 0;
					uint8_t rl;
					while(bytes<bu16)
					{
						ifs.read((char*)&bu8,1);  bytes++;
						if(bu8==0xed)
						{
							ifs.read((char*)&bu8,1);  bytes++;
							if(bu8==0xed)
							{
								ifs.read((char*)&rl,1); bytes++;
								ifs.read((char*)&bu8,1); bytes++;
								for(int k=0;k<rl;k++)
								{
									poke(addr,bu8);addr++;
								}
							}
							else
							{
								poke(addr,0xed);
								addr++;
								poke(addr,bu8);
								addr++;
							}
						}
						else 
						{
							poke(addr,bu8);
							addr++;
						}
					}
				}
			}
		}
		
			
		PRINT(version);
		PRINT(isCompressed);
		return 1;
	}
	else
	{
		int addr = 0x4000;
		uint8_t rl;
		if(!isCompressed)
		{
			//read 48K raw
			for(int k=0;k<0x10000-0x4000;k++)
			{
				ifs.read((char*)&bu8,1); 
				poke(addr,bu8);addr++;
			}
		}
		else
		{
			while(addr<0x10000)
			{
				ifs.read((char*)&bu8,1); 
				if(ifs)
				{
					if(bu8==0xed)
					{
						ifs.read((char*)&bu8,1); 
						if(bu8==0xed)
						{
							ifs.read((char*)&rl,1); 
							ifs.read((char*)&bu8,1); 
							for(int k=0;k<rl;k++)
							{
								poke(addr,bu8);addr++;
							}
						}
						else
						{
							poke(addr,0xed);
							addr++;
							poke(addr,bu8);
							addr++;
						}
					}
					else 
					{
						poke(addr,bu8);
						addr++;
					}
				}
				else
				{
					PRINT(addr);
					addr = 0x10000;
				}
					
			}
		}
		PRINT(version);
		PRINT(isCompressed);
		return 1;
	}
	
}
#ifndef O_BINARY
#define O_BINARY 0
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char *progname="spec program";

int
read_file( libspectrum_byte **buffer, size_t *length, const char *filename )
{
  int fd;
  struct stat info;
  ssize_t bytes;

  fd = open( filename, O_RDONLY | O_BINARY );
  if( fd == -1 ) {
    fprintf( stderr, "%s: couldn't open `%s': %s\n", progname, filename,
	     strerror( errno ) );
    return errno;
  }

  if( fstat( fd, &info ) ) {
    fprintf( stderr, "%s: couldn't stat `%s': %s\n", progname, filename,
	     strerror( errno ) );
    return errno;
  }

  *length = info.st_size;
  *buffer = libspectrum_new( libspectrum_byte, *length );

  bytes = read( fd, *buffer, *length );
  if( bytes == -1 ) {
    fprintf( stderr, "%s: error reading from `%s': %s\n", progname, filename,
	     strerror( errno ) );
    return errno;
  } else if( bytes < *length ) {
    fprintf( stderr, "%s: read only %lu of %lu bytes from `%s'\n", progname,
	     (unsigned long)bytes, (unsigned long)*length, filename );
    return 1;
  }

  if( close( fd ) ) {
    fprintf( stderr, "%s: error closing `%s': %s\n", progname, filename,
	     strerror( errno ) );
    return errno;
  }

  return 0;
}
typedef int test_return_t; 
#define TEST_INCOMPLETE 1
#define TEST_FAIL              2
#define TEST_PASS             0 
void swapBt(uint16_t & wd)
{
	u8 * pnt =(u8 *)&wd; 
	std::swap(pnt[0],pnt[1]);
}

void dump(const char *filename ,unsigned char* rimage)
{
	ofstream ofs(filename,ios::out|ios::binary);
	uint8_t buffer[24][32*3];
	for(int yb=0;yb<24;yb++)
	{
		for(int xb=0;xb<32;xb++)
		{
			int base = yb*10*320+xb*10;
			buffer[yb][xb*3+0] = rimage[base*4+0];
			buffer[yb][xb*3+1] = rimage[base*4+1];
			buffer[yb][xb*3+2] = rimage[base*4+2];
		}
	}
	ofs.write((const char*)&buffer[0][0],24*32*3);
	ofs.write((const char*)&reg,sizeof(reg));
	ofs.write((const char*)&reg_,sizeof(reg_));
	ofs.write((const char*)&IM,sizeof(IM));
	ofs.write((const char*)&IFF1,sizeof(IFF1));
	ofs.write((const char*)&IFF2,sizeof(IFF2));
	ofs.write((const char*)&halt,sizeof(halt));
	ofs.write((const char*)&RAM,sizeof(RAM));
	//~ extern u8 IM;
//~ extern u8 IFF1;
//~ extern u8 IFF2;
//~ extern u8 halt;

	//~ ofs.write((const char*)&AF,sizeof(A));
	//~ ofs.write((const char*)&F,sizeof(F));
}
void dumpR(const char *filename)
{
	if(strlen(filename))
	{
		ifstream ifs(filename,ios::in|ios::binary);
		uint8_t buffer[24][32*3];
		//~ for(int yb=0;yb<24;yb++)
		//~ {
			//~ for(int xb=0;xb<32;xb++)
			//~ {
				//~ int base = yb*10*320+xb*10;
				//~ buffer[yb][xb*3+0] = rimage[base*4+0];
				//~ buffer[yb][xb*3+1] = rimage[base*4+1];
				//~ buffer[yb][xb*3+2] = rimage[base*4+2];
			//~ }
		//~ }
		ifs.read(( char*)&buffer[0][0],24*32*3);
		ifs.read(( char*)&reg,sizeof(reg));
		ifs.read(( char*)&reg_,sizeof(reg_));
		ifs.read(( char*)&IM,sizeof(IM));
		ifs.read(( char*)&IFF1,sizeof(IFF1));
		ifs.read(( char*)&IFF2,sizeof(IFF2));
		ifs.read(( char*)&halt,sizeof(halt));
		ifs.read(( char*)&RAM,sizeof(RAM));
	}
	//~ extern u8 IM;
//~ extern u8 IFF1;
//~ extern u8 IFF2;
//~ extern u8 halt;

	//~ ofs.write((const char*)&AF,sizeof(A));
	//~ ofs.write((const char*)&F,sizeof(F));
}

static test_return_t test_25( const char *filename )
{
	PRINT(filename);
  libspectrum_byte *buffer = NULL;
  size_t filesize = 0, length = 0;
  libspectrum_snap *snap;
  int flags;
  test_return_t r = TEST_INCOMPLETE;

  if( read_file( &buffer, &filesize, filename ) ) return TEST_INCOMPLETE;

  snap = libspectrum_snap_alloc();
  if( libspectrum_snap_read( snap, buffer, filesize, LIBSPECTRUM_ID_UNKNOWN,
			     filename ) != LIBSPECTRUM_ERROR_NONE ) {
    fprintf( stderr, "%s: reading `%s' failed\n", progname, filename );
	
				     
    libspectrum_snap_free( snap );
    libspectrum_free( buffer );
    return TEST_INCOMPLETE;
  }
    libspectrum_machine machine=  libspectrum_snap_machine(snap);
	PRINT( libspectrum_machine_name(machine));
	PRINT( libspectrum_timings_ay_speed(machine));
	PRINT(libspectrum_timings_processor_speed(machine));
	PRINT(libspectrum_timings_left_border(machine));
	PRINT(libspectrum_timings_horizontal_screen(machine));
	PRINT(libspectrum_timings_right_border(machine));
	PRINT(libspectrum_timings_horizontal_retrace(machine));
	PRINT(libspectrum_timings_tstates_per_line(machine));
	PRINT(libspectrum_timings_tstates_per_frame(machine));
	PRINT(libspectrum_timings_interrupt_length(machine));
  
	IFF1 = libspectrum_snap_iff1(snap) ;
	IFF2 = libspectrum_snap_iff2(snap) ;
	IM = libspectrum_snap_im(snap);	
	halt = libspectrum_snap_halted(snap);
	A    = libspectrum_snap_a(snap);
	F    = libspectrum_snap_f(snap);
	BC  = libspectrum_snap_bc(snap);
	DE  = libspectrum_snap_de(snap);
	HL  = libspectrum_snap_hl(snap);
	//~ L = libspectrum_snap_c(snap);
  	A_    = libspectrum_snap_a_(snap);
	F_    = libspectrum_snap_f_(snap);
	BC_  = libspectrum_snap_bc_(snap);
	DE_  = libspectrum_snap_de_(snap);
	HL_  = libspectrum_snap_hl_(snap);
	IX     = libspectrum_snap_ix(snap);
	IY     = libspectrum_snap_iy(snap);
	SP = libspectrum_snap_sp(snap);
	PC = libspectrum_snap_pc(snap);
	I  = libspectrum_snap_i(snap);
  	R  = libspectrum_snap_r(snap);
	R7 = R;
	MEMPTR = libspectrum_snap_memptr(snap);
	tstates = libspectrum_snap_tstates(snap);
	interrupts_enabled_at = libspectrum_snap_last_instruction_ei(snap);
	cout<<hex;
	PRINT((int)libspectrum_snap_last_instruction_ei(snap));
	PRINT((int)libspectrum_snap_last_instruction_set_f(snap));
	PRINT((int)libspectrum_snap_tstates(snap));
	PRINT((int)libspectrum_snap_out_ula(snap));
	PRINT((int)libspectrum_snap_kempston_mouse_active(snap));
	PRINT((int)libspectrum_snap_joystick_active_count(snap));
	
	//~ swapBt(MEMPTR);
	//~ swapBt(PC);
	//~ swapBt(SP);
	//~ swapBt(BC);
	//~ swapBt(DE);
	//~ swapBt(HL);
	//~ swapBt(BC_);
	//~ swapBt(DE_);
	//~ swapBt(HL_);
	//~ swapBt(IX);
	//~ swapBt(IY);
	PRINT(MEMPTR);
	PRINT((uint16_t)IFF1);
	PRINT((uint16_t)IFF2);
	PRINT((uint16_t)IM);
	PRINT((uint16_t)halt);
	PRINT((uint16_t)A);
	PRINT((uint16_t)F);
	PRINT(BC);
	PRINT(DE);
	PRINT(HL);
	PRINT((uint16_t)A_);
	PRINT((uint16_t)F_);
	PRINT(BC_);
	PRINT(DE_);
	PRINT(HL_);
	PRINT(IX);
	PRINT(IY);
	PRINT(SP);
	PRINT(PC);
	PRINT((uint16_t)I);
	PRINT((uint16_t)R);
	
	printf("MP=%04x\n",MEMPTR);
	printf("SP=%04x\n",SP);
	printf("PC=%04x\n",PC);
	printf("DE=%04x\n",DE);
	printf("BC=%04x\n",BC);
	printf("HL=%04x\n",HL);
	printf("H=%02x\n",H);
	printf("L=%02x\n",L);
	//~ swapBt(MEMPTR);
	//~ swapBt(PC);
	//~ swapBt(SP);
	//~ swapBt(SP);
	int rp = 0;
	int pA[8]= 
	{
		0xc000,
		0,
		0x8000,
		0,
		0,
		0x4000,
		0,
		0
	};
	for(int p=0;p<8;p++)
	{
		u8* page = libspectrum_snap_pages(snap,p);
		if(page)
		{
			for(int k=0;k<0x4000;k++)
			{
				poke(pA[p]+k,page[k]);
			}
			PRINT(page);
			rp++;
			PRINT("OK");
		}
		else
		{
			PRINT("NOT OK");
		}
	}
	//~ libspectrum_snap_tstates(snap);
	//~ libspectrum_snap_last_instruction_ei(snap);
	//~ libspectrum_snap_last_instruction_set_f(snap);
  
//~ extern u8 m_cycle;
//~ extern u8 IM;
//~ extern u8 IFF1;
//~ extern u8 IFF2;
//~ extern u8 halt;

  libspectrum_free( buffer );
  buffer = NULL;
  /*
  if( libspectrum_snap_write( &buffer, &length, &flags, snap,
                              LIBSPECTRUM_ID_SNAPSHOT_SNA, NULL, 0 ) != 
      LIBSPECTRUM_ERROR_NONE ) {
    fprintf( stderr, "%s: serialising to SNA failed\n", progname );
    libspectrum_snap_free( snap );
    return TEST_INCOMPLETE;
  }

  libspectrum_snap_free( snap );
  snap = libspectrum_snap_alloc();

  if( libspectrum_snap_read( snap, buffer, length, LIBSPECTRUM_ID_SNAPSHOT_SNA,
                             NULL ) != LIBSPECTRUM_ERROR_NONE ) {
    fprintf( stderr, "%s: restoring from SNA failed\n", progname );
    libspectrum_snap_free( snap );
    libspectrum_free( buffer );
    return TEST_INCOMPLETE;
  }

  libspectrum_free( buffer );

  if( libspectrum_snap_pc( snap ) != 0x1234 ) {
    fprintf( stderr, "%s: PC is 0x%04x, not the expected 0x1234\n", progname,
             libspectrum_snap_pc( snap ) );
    r = TEST_FAIL;
  } else if( libspectrum_snap_sp( snap ) != 0x8000 ) {
    fprintf( stderr, "%s: SP is 0x%04x, not the expected 0x8000\n", progname,
             libspectrum_snap_sp( snap ) );
    r = TEST_FAIL;
  } else {
    r = TEST_PASS;
  }

  libspectrum_snap_free( snap );
*/
  r = TEST_PASS;
  return r;
}

string inputFileName; 
string inputFileNameS; 
bool bDebugMode = false;

#define GLUT_KEY_CTRL_L             0x0072
#define KEY_OFF 0x1000
#define GLUT_KEY_DELETE 0x7f
#define GLUT_KEY_TAB 0x9
#define GLUT_KEY_CTRL_D 4
#define GLUT_KEY_CTRL_S 19
#define GLUT_KEY_ESC 27
#define GLUT_KEY_SHIFT_L            0x0070

#define GLUT_KEY_ENTER 	13
//~ #define CAPS_SHIFT 	GLUT_KEY_SHIFT_L
//~ #define SYMB_SHIFT 	GLUT_KEY_CTRL_L
#define ENTER 		GLUT_KEY_ENTER
#define SPACE 		' ' 		

#define CAPS_SHIFT 	1
#define SYMB_SHIFT 	2
extern "C"
{
//adddress bus:	//8	//9	//10	//11	//12	//13	//14	//15		
const int keyMatrix[5][8] = {
	{ CAPS_SHIFT	,'A'	,'Q'	,'1'	,'0'	,'P'	,ENTER	,SPACE		},	// d0
	{ 'Z'		,'S'	,'W'	,'2'	,'9'	,'O'	,'L'	,SYMB_SHIFT	},	// d1
	{ 'X'		,'D'	,'E'	,'3'	,'8'	,'I'	,'K'	,'M'		},	// d2
	{ 'C'		,'F'	,'R'	,'4'	,'7'	,'U'	,'J'	,'N'		},	// d3
	{ 'V'		,'G'	,'T'	,'5'	,'6'	,'Y'	,'H'	,'B'		}	// d4	
	};

uint8_t	IsPressed[5][8];  //public
}

class   KeyMatrix
{
	std::map<int,pair<int,int> > cache;
	public:
	KeyMatrix()
	{
		for(int y=0;y<5;y++)
		{
			for(int x=0;x<8;x++)
			{
				IsPressed[y][x] = false;
				cache[keyMatrix[y][x]]=std::pair<int,int>(x,y);
			}
		}
		
	}
//~ bool    findKey(int key,int & adressLine,int & dataLine)
//~ {
	//~ for(int y=0;y<5;y++)
	//~ {
		//~ for(int x=0;x<10;x++)
		//~ {
			//~ if(key==keyMatrix[y][x])
			//~ {
				//~ adressLine = x;
				//~ dataLine = y;
				//~ return true;
			//~ }
		//~ }
	//~ }
	//~ return false;
//~ }
	bool    findKey(int key,int & adressLine,int & dataLine)
	{
		auto pos = cache.find(key);
		if(pos!=cache.end())
		{
			adressLine = pos->second.first;
			dataLine = pos->second.second;
			return true;
		}
		return false;
	}
	void keyUpDown(int key,bool on)
	{
		int adressLine;
		int dataLine;
		if(findKey(key,adressLine,dataLine))
		{
			if(bDebugMode)
			{
				PRINT(on);
			}
			IsPressed[dataLine][adressLine] = on;
		}
		else
		{
			//nothing
		}
	}
	
};

int flag = 1;

//~ #include <system.h>

extern int32_t tstates;

class Render  //:public cChain
{
public:
	GLuint                texName;
	//~ TextureArray*         image;
	KeyMatrix             keyMatrix;

	//~ unsigned short *fimage;
	unsigned char   *rimage;
	string status;
	int      WWW;
	int      HHH;
	int        images_cnt;
        int        overall_images;
        int        time_ms;
	float     fps;
	int         gl_image;
	bool bYUUV;
	//~ psv   temp;
	int imageW;
	int imageH;
	int textSize;
	int KeyStartTime;

	//~ int window;
	//~ int level;
	//~ vector<psv> Que;
	int           winW;
	int           winH;
	bool        bReady;
        Render()//:temp(tNameSpace)
	{
		winW = 512;
		winH = 512;
		WWW=winW;
		HHH=winH;
		//~ image = NULL; 
		texName = 0;
		rimage = NULL;
		gl_image = 0;
		overall_images =0;
		time_ms =0;
		images_cnt =0;
		fps =0;
	} 
	void paintModel() ;
	void displayMain();   
	//~ void sKeyboard(psv& event);
	//~ void keyboard(psv& event); 
	void keyboard(int key,int x,int y,int mod);
	void mouseButton(int button, int state,int mod, int x, int y);
	void mouseMotion( int x, int y);
	
	void reshape(int w,int h)
	{ 
		winW = w;winH=h;
		//~ PRINT(winW);
		//~ PRINT(winH);
		if((winW==0)|(winH==0)) return;
	}
	void idle()
	{
		//~ tstates
		if((glutGet(GLUT_ELAPSED_TIME)-time_ms)>20)
		{	
			if(!texName)
			{
				init();
				glutReshapeWindow(640,480);
			}
			time_ms = glutGet(GLUT_ELAPSED_TIME);
			int stopt = tstates+69888u;
			for(;tstates<stopt;)
			{
				z80_run();
				//~ PRINT(tstates);
			}
			ftime = glutGet(GLUT_ELAPSED_TIME)-time_ms;
			if(tstates>0x10000000)
			{
				tstates-=0x10000000;
				interrupts_enabled_at-=0x10000000;
			}
			//~ tstates-=69888u;
			//~ interrupts_enabled_at-=69888u;
			if(flag)
			{
				std::cout<<hex;
				PRINT(PC);
				std::cout<<dec;
				flag = 0;
				
			}
			{
				//~ KeyStartTime =  glutGet(GLUT_ELAPSED_TIME);
				if(rimage)
				{
					//~ PRINT("rimage");
					int Rc= !!(border&2);
					int Gc= !!(border&4);
					int Bc= !!(border&1);
					for(int y=0;y<240;y++)
					{
						for(int x=0;x<320;x++)
						{
							int base = y*imageW+x;
							rimage[base*4+0] = 0xd7*Rc;
							rimage[base*4+1] = 0xd7*Gc;
							rimage[base*4+2] = 0xd7*Bc;
							rimage[base*4+3] = 128;
						}
					}
					for(int y=0;y<192;y++)
					{
						for(int px=0;px<32;px++)
						{
							uint8_t attr = RAM[(y/8)*32+px+0x5800-0x4000];
							int RInc= !!(attr&2);
							int GInc= !!(attr&4);
							int BInc= !!(attr&1);

							int Rpap= !!(attr&16);
							int Gpap= !!(attr&32);
							int Bpap= !!(attr&8);
							
							int Br = !!(attr&64);
							int Fl = !!(attr&128);
							if(Fl==1&&((glutGet(GLUT_ELAPSED_TIME)/500)&1))
							{
								std::swap(RInc,Rpap);
								std::swap(GInc,Gpap);
								std::swap(BInc,Bpap);
							}
							int addr =  (px)| ((y<<8)&0x700) | ((y<<2)&0b11100000) | ((y<<5)&0x1800); 
							for(int bit=0;bit<8;bit++)
							{
								int base = y*imageW+px*8+bit+(320-256)/2+(240-192)/2*imageW;
								int bt = ((RAM[(addr)]>>(7-bit))&1);
								rimage[base*4+0] = (Br?0xff:0xd7)*(bt?(RInc):(Rpap));
								rimage[base*4+1] = (Br?0xff:0xd7)*(bt?(GInc):(Gpap));
								rimage[base*4+2] = (Br?0xff:0xd7)*(bt?(BInc):(Bpap));
								rimage[base*4+3] = 128;
							}
						}
					}
				}
				screen_IRQ = 1;
				//~ halt = 0;
				glutPostRedisplay();
				
			}
		overall_images++;
		}
		
		//~ int newTime = glutGet(GLUT_ELAPSED_TIME);
		if(!bReady)
		{	
			usleep(1000);
			return ;
		}	
	}
	void init()
	{
		textSize = 1;
		imageW = 320;
		imageH =  240;
		while(textSize<max(imageW,imageH))
		{
			textSize*=2;
		}
		if(texName)	
		{
			glDeleteTextures(1,&texName);
			texName = 0;
		}
		if(rimage)	
		{
			delete rimage;
		}
		//~ PRINT("go init"); 
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
	glDisable(GL_LOGIC_OP);
	glDisable(GL_STENCIL_TEST);
	
	glPixelTransferi(GL_MAP_COLOR, GL_FALSE);
	glPixelTransferi(GL_MAP_STENCIL,GL_FALSE);
	glPixelTransferi(GL_RED_SCALE, 1);
	glPixelTransferi(GL_RED_BIAS, 0);
	glPixelTransferi(GL_GREEN_SCALE, 1);
	glPixelTransferi(GL_GREEN_BIAS, 0);
	glPixelTransferi(GL_BLUE_SCALE, 1);
	glPixelTransferi(GL_BLUE_BIAS, 0);
	glPixelTransferi(GL_ALPHA_SCALE, 1);
	glPixelTransferi(GL_ALPHA_BIAS, 0); 
 
		
		PRINT(glGetError());
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
		PRINT(glGetError());
	
	glDisable(GL_MULTISAMPLE);
		
		PRINT(glGetError());
		glEnable(GL_TEXTURE_2D);
		
		glGenTextures(1,&texName);
		glBindTexture(GL_TEXTURE_2D,texName);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, textSize,textSize, 0,  GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		PRINT(glGetError());
		//~ image = new TextureArray(textSize,textSize,1,u_4x8);
			
			//~ PRINT(image);
			
		rimage = new unsigned char[imageW*imageH*4];
			//~ PRINT(image);
		memset(rimage,0,sizeof(*rimage)*imageW*imageH*4);
		//~ image = new TextureArray(imageW,imageH,1,u_4x8);
		
	}
	void runD(); 
        ~Render()
	{
	} 
}; 


Render * render; 
void Render::keyboard(int key,int x,int y,int mod)
{
	if(bDebugMode)
	{
		char buff[0x20];
		sprintf(buff,"key=%02x,mod=%02x\n",key,mod);
		cout<<buff<<flush;
	}
	char TU = toupper(key);
	 
	if(key == GLUT_KEY_ENTER)
	{
		keyMatrix.keyUpDown(ENTER,mod&0x10?false:true);
	}
	else if(key == GLUT_KEY_SHIFT_L && (mod&0x20))
	{
		keyMatrix.keyUpDown(CAPS_SHIFT,mod&0x10?false:true);
	}
	else if(key == GLUT_KEY_CTRL_L && (mod&0x20))
	{
		keyMatrix.keyUpDown(SYMB_SHIFT,mod&0x10?false:true);
	}
	else if (key==0x21&&(mod&0x01))
	{
		keyMatrix.keyUpDown('1',mod&0x10?false:true);
	}
	else if (key==0x40&&(mod&0x01))
	{
		keyMatrix.keyUpDown('2',mod&0x10?false:true);
	}
	else if (key==0x23&&(mod&0x01))
	{
		keyMatrix.keyUpDown('3',mod&0x10?false:true);
	}
	else if (key==0x24&&(mod&0x01))
	{
		keyMatrix.keyUpDown('4',mod&0x10?false:true);
	}
	else if (key==0x25&&(mod&0x01))
	{
		keyMatrix.keyUpDown('5',mod&0x10?false:true);
	}
	else if (key==0x5e&&(mod&0x01))
	{
		keyMatrix.keyUpDown('6',mod&0x10?false:true);
	}
	else if (key==0x26&&(mod&0x01))
	{
		keyMatrix.keyUpDown('7',mod&0x10?false:true);
	}
	else if (key==0x2a&&(mod&0x01))
	{
		keyMatrix.keyUpDown('8',mod&0x10?false:true);
	}
	else if (key==0x28&&(mod&0x01))
	{
		keyMatrix.keyUpDown('9',mod&0x10?false:true);
	}
	else if (key==0x29&&(mod&0x01))
	{
		keyMatrix.keyUpDown('0',mod&0x10?false:true);
	}
	else if (key==0x31&&(mod&0x02))
	{
		keyMatrix.keyUpDown('1',mod&0x10?false:true);
	}
	else if (key==0x00&&(mod&0x02))
	{
		keyMatrix.keyUpDown('2',mod&0x10?false:true);
	}
	else if (key==0x1b&&(mod&0x02))
	{
		keyMatrix.keyUpDown('3',mod&0x10?false:true);
	}
	else if (key==0x1c&&(mod&0x02))
	{
		keyMatrix.keyUpDown('4',mod&0x10?false:true);
	}
	else if (key==0x1d&&(mod&0x02))
	{
		keyMatrix.keyUpDown('5',mod&0x10?false:true);
	}
	else if (key==0x1e&&(mod&0x02))
	{
		keyMatrix.keyUpDown('6',mod&0x10?false:true);
	}
	else if (key==0x1f&&(mod&0x02))
	{
		keyMatrix.keyUpDown('7',mod&0x10?false:true);
	}
	else if (key==0x7f&&(mod&0x02))
	{
		keyMatrix.keyUpDown('8',mod&0x10?false:true);
	}
	else if (key==0x39&&(mod&0x02))
	{
		keyMatrix.keyUpDown('9',mod&0x10?false:true);
	}
	else if (key==0x30&&(mod&0x02))
	{
		keyMatrix.keyUpDown('0',mod&0x10?false:true);
		if(joystickMode==3)
		{
			if(mod&0x10)
			{
				kempston|=0x10 ; 
			}
			else
			{
				kempston&=~0x10 ; 
			}
			
		}
	}
	else if (key==0x64&&(mod&0x20)) //left
	{
		if(joystickMode==0) //cursor
		{
			keyMatrix.keyUpDown('5',mod&0x10?false:true);
		}
		else if(joystickMode==1) //sinclair1
		{
			keyMatrix.keyUpDown('6',mod&0x10?false:true);
		}
		else if(joystickMode==2) //sinclair2
		{
			keyMatrix.keyUpDown('1',mod&0x10?false:true);
		}
		else if(joystickMode==3) //sinclair2
		{
			if(mod&0x10)
			{
				kempston|=0x2 ; 
			}
			else
			{
				kempston&=~0x2 ; 
			}
		}
			
	}
	else if (key==0x67&&(mod&0x20)) //down
	{
		//~ keyMatrix.keyUpDown('6',mod&0x10?false:true);
		if(joystickMode==0) //cursor
		{
			keyMatrix.keyUpDown('6',mod&0x10?false:true);
		}
		else if(joystickMode==1) //sinclair1
		{
			keyMatrix.keyUpDown('8',mod&0x10?false:true);
		}
		else if(joystickMode==2) //sinclair2
		{
			keyMatrix.keyUpDown('3',mod&0x10?false:true);
		}
		else if(joystickMode==3) //sinclair2
		{
			if(mod&0x10)
			{
				kempston|=0x4 ; 
			}
			else
			{
				kempston&=~0x4 ; 
			}
		}
	}
	else if (key==0x65&&(mod&0x20)) //up
	{
		//~ keyMatrix.keyUpDown('7',mod&0x10?false:true);
		if(joystickMode==0) //cursor
		{
			keyMatrix.keyUpDown('7',mod&0x10?false:true);
		}
		else if(joystickMode==1) //sinclair1
		{
			keyMatrix.keyUpDown('9',mod&0x10?false:true);
		}
		else if(joystickMode==2) //sinclair2
		{
			keyMatrix.keyUpDown('4',mod&0x10?false:true);
		}
		else if(joystickMode==3) //sinclair2
		{
			if(mod&0x10)
			{
				kempston|=0x8 ; 
			}
			else
			{
				kempston&=~0x8 ; 
			}
		}
	}
	else if (key==0x66&&(mod&0x20)) //right
	{
		//~ keyMatrix.keyUpDown('8',mod&0x10?false:true);
		if(joystickMode==0) //cursor
		{
			keyMatrix.keyUpDown('8',mod&0x10?false:true);
		}
		else if(joystickMode==1) //sinclair1
		{
			keyMatrix.keyUpDown('7',mod&0x10?false:true);
		}
		else if(joystickMode==2) //sinclair2
		{
			keyMatrix.keyUpDown('2',mod&0x10?false:true);
		}
		else if(joystickMode==3) //sinclair2
		{
			if(mod&0x10)
			{
				kempston|=0x1 ; 
			}
			else
			{
				kempston&=~0x1 ; 
			}
		}
	}
	else if(TU>='A'&&TU<='Z'||(TU==' ')||(TU>='0'&&TU<='9'))
	{
		keyMatrix.keyUpDown(TU,mod&0x10?false:true);
	}
	else  if((key==0x1b)&&!(mod&1))  ///esc
	{
		if(!mod)
		{
			joystickMode = (joystickMode+1)%4;
		}
	}
	switch(key)
	{
		case GLUT_KEY_F1:
			break;
		case GLUT_KEY_F2:
			dump("specci.dump",rimage);
			break;
		case GLUT_KEY_UP:
		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_DOWN:
		case GLUT_KEY_PAGE_DOWN:
			break;
	}	
	return ;	
}
#define TEXT_TYPE GLUT_BITMAP_TIMES_ROMAN_24
void Render::paintModel() 
{

	ostringstream ss;
	ss.setf(ios::left);
	ss<<"Images "<<setw(5)<<overall_images<<setw(5)<<"fps "<<std::setprecision(1)<<std::fixed<<fps<<setw(5)<<" "<<std::setprecision(3)<<imageW<<"x"<<imageH<<" "<<ftime<<" ";
	if(status.length())
	{
		ss<<status;
	}
	string sString(ss.str());
	//~ PRINT(texName);
	if(texName)
	{
		//~ PRINT("put");
		//~ status = string("");
		//~ PRINT(window);
		//~ PRINT(window);
	glColorMask(1,1,1,1);
	glDepthMask(0);
		/*
	glShadeModel (GL_SMOOTH);  
	//~ glShadeModel (GL_FLAT); 
	glDisable(GL_ALPHA_TEST);  
	glDisable(GL_SCISSOR_TEST);
	glDisable(GL_BLEND);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_DEPTH_TEST); 
	glDisable(GL_POLYGON_OFFSET_FILL);
	//glDisable(GL_DEPTH_TEST);
	//glDisable(GL_DEPTH_TEST);
	glCullFace(GL_FRONT_AND_BACK);
        for(int i=0;i<GL_MAX_CLIP_PLANES;i++)
	{	
		glDisable(GL_CLIP_PLANE0+i);
	}
	*/
	//~ glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_FASTEST);
	//~ glEnable(GL_BLEND);
	//~ glBlendFunc( GL_SRC_ALPHA, GL_ONE); 
	//~ glEnable(GL_FRONT_AND_BACK); 
	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texName); 
		glTexSubImage2D(GL_TEXTURE_2D,0,0,0,imageW,imageH,GL_RGBA,GL_UNSIGNED_BYTE,rimage);
		//~ PRINT(glGetError());
		//~ image->putSub(rimage,0,0,0,imageW,imageH);
		
		//~ PRINT("put OK");
		
		GLfloat aspect = (GLfloat) winH/(GLfloat)winW;
		//~ PRINT("View port");
		//~ PRINT(winW);
		//~ PRINT(winH);
		glViewport(0,0,winW,winH);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		GLfloat size_   = 1.0;
		//~ PRINT(aspect);
		glOrtho(-size_, size_, -size_*aspect, +size_*aspect, -size_, size_);
		float iimAsp = (GLfloat) imageH/(GLfloat)imageW;
		//~ PRINT("model");
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
			//~ glDisable(GL_TEXTURE_3D); 
		
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0); 
		glBindTexture(GL_TEXTURE_2D, texName); 
		//~ image->texArray[0]->bind();
		glColor3f(0.0f,0.0f,0.0f);
		//~ PRINT("paint quads");
		if(!gl_image)
		{
			glBegin( GL_QUADS );
			glTexCoord2f(0.0,float(imageH)/textSize); glVertex2f(-1,-iimAsp);
			glTexCoord2f(float(imageW)/textSize,float(imageH)/textSize); glVertex2f(1.0,-iimAsp);
			glTexCoord2f(float(imageW)/textSize,0.0); glVertex2f(1.0,iimAsp);
			glTexCoord2f(0.0,0.0); glVertex2f(-1,iimAsp);
			glEnd();	
		}
		else
		{
			glBegin( GL_QUADS );
			glTexCoord2f(0.0,				  0.0); 					
				glVertex2f(-1,-iimAsp);
			glTexCoord2f(float(imageW)/textSize,0.0); 	
				glVertex2f(1.0,-iimAsp);
			glTexCoord2f(float(imageW)/textSize,				float(imageH)/textSize); 					
				glVertex2f(1.0,iimAsp);
			glTexCoord2f(0.0,								float(imageH)/textSize); 									
				glVertex2f(-1,iimAsp);
			glEnd();	
		}
		//~ PRINT("paint fps");
		
		glDisable(GL_TEXTURE_2D);
		char sbuff[0x30];
		float fpos = 0.9;
		float fdelta = -1.8/16;
		char* joystickModeC[] = {"cursor","sinclair1","sinclair2","kempston"};
		if(bDebugMode)
		{
		sprintf(sbuff,"IFF1 %x",IFF1);	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"IFF2 %x",IFF2);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta; 
		sprintf(sbuff,"halt %x",halt);    	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"IM %x",IM);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"PC %x",PC);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"IX %x",IX);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"IY %x",IY);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"interrupts_enabled_at %d",interrupts_enabled_at);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		sprintf(sbuff,"tstates %d",tstates);   	glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		}
		sprintf(sbuff,"Joy %s",joystickModeC[joystickMode]);glColor3f(1.0f, 1.0f, 0.0f);glRasterPos2f(-0.91,aspect*fpos);for (unsigned int iChar = 0; iChar < strlen(sbuff); ++iChar) glutBitmapCharacter(TEXT_TYPE, sbuff[iChar]); fpos+=fdelta;
		
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(-0.91,aspect*-0.91);
		for (unsigned int iChar = 0; iChar < sString.length(); ++iChar)
		{	
			glutBitmapCharacter(TEXT_TYPE, sString[iChar]); 
	
		}	
		glColor3f(1.0f, 1.0f, 0.0f);
		glRasterPos2f(-0.9,aspect*-0.9);
		for (unsigned int iChar = 0; iChar < sString.length(); ++iChar)
		{	
			glutBitmapCharacter(TEXT_TYPE, sString[iChar]); 
	
		}	
	} 
}

void Render ::displayMain()
{ 
	if((winW==0)|(winH==0)) return;
	glViewport(0, 0, winW,winH);
	glColorMask(1,1,1,1);
	glDepthMask(1);
	glClearColor(0.2, 0.2, 0.2, 0.2);	
	//~ glClearDepth(1.0f);	
	//~ glDepthFunc(GL_LESS); 
	//~ glEnable(GL_DEPTH_TEST);
	//~ glFrontFace(GL_CCW);
	//~ glDisable(GL_CULL_FACE); 
	//~ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//~ PRINT("display");
	paintModel() ;
	//~ PRINT("paintModel OK");
	//~ glColorMask(1,1,1,1);
	glViewport(0, 0, winW,winH);
	//~ PRINT("draw UI");
	//~ PRINT("draw UI ok");
	glutSwapBuffers();
	bReady = true;
}




void DisplayMain(void)
{
	render->displayMain();
}

void Keyboard(unsigned char key,int x,int y)
{
	render->keyboard(key,x,y,glutGetModifiers());
}


void KeyboardUp(unsigned char key,int x,int y)
{
	render->keyboard(key,x,y,glutGetModifiers()|0x10);
}

void SKeyboard(int key,int x,int y)
{
	render->keyboard(key,x,y,glutGetModifiers()|0x20);
}

void SKeyboardUp(int key,int x,int y)
{
	render->keyboard(key,x,y,glutGetModifiers()|0x30);
}

void Idle(void)
{
	render->idle();
}

void Reshape(int w, int h)
{
	render->reshape(w,h);
}

void
MouseButton(int button, int state, int x, int y)
{
	render->mouseButton(button,state,glutGetModifiers(),x,y);
}

void
MouseMotion(int x, int y)
{
	render->mouseMotion(x,y);
}

void DialsFunc(int dial,int val)
{
}

void	Render::mouseButton(int button, int state,int mod, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) 
	{
	}
	else if (button == GLUT_MIDDLE_BUTTON) 
	{
	}
	else if (button == GLUT_RIGHT_BUTTON) 
	{
	}
}

void	Render::mouseMotion( int x, int y)
{
	//~ glutPostRedisplay();
}

 
void Render::runD() 
{
		try
		{ 
			//~ init_gpu();
			
			glutReshapeFunc(::Reshape);
			glutDisplayFunc(::DisplayMain);
			glutKeyboardFunc(::Keyboard);
			glutKeyboardUpFunc(::KeyboardUp);
			
			glutSpecialFunc(::SKeyboard);
			glutSpecialUpFunc(::SKeyboardUp);
			glutMotionFunc(::MouseMotion);
			glutMouseFunc(::MouseButton);
			glutIdleFunc(::Idle);
			glutDialsFunc(::DialsFunc);
			glutButtonBoxFunc(::DialsFunc);
			//~ glutReshapeWindow(640,480); 
			//~ images = new ImageStorage;
			//~ images->angle = config["bb"]["angle"]["value"].rFloat();
			z80_reset(1);
			
			if(inputFileName!=string(""))
			{
				/*
				typedef void* (*libspectrum_malloc_fn_t)( size_t size );
				typedef void* (*libspectrum_calloc_fn_t)( size_t nmemb, size_t size );
				typedef void* (*libspectrum_realloc_fn_t)( void *ptr, size_t size );
				typedef void (*libspectrum_free_fn_t)( void *ptr );

				typedef struct libspectrum_mem_vtable_t {
				  libspectrum_malloc_fn_t malloc;
				  libspectrum_calloc_fn_t calloc;
				  libspectrum_realloc_fn_t realloc;
				  libspectrum_free_fn_t free;
				} libspectrum_mem_vtable_t;

				void libspectrum_mem_set_vtable( libspectrum_mem_vtable_t *table )
				//~ */
				if(my80_read(inputFileName.c_str() ) )
				{
					//~ PRINT(test_25(inputFileName.c_str()));
				}
			}
			else if (inputFileNameS!=string(""))
			{
				dumpR(inputFileNameS.c_str());
			}
			
			//~ images->read("/home/gpu/Gears/bin/tata.ns");
		}
		catch(...)
		{
			PRINT("ERRPR");
		}
		glutMainLoop();
}
//~ #include <nsparser.h>
//~ string inputFileName;
//~ #ifdef __STRICT_ANSI__
#undef  __STRICT_ANSI__
//~ #include <float.h> 
//~ #include_next <float.h> 
//~ #endif
int main(int pn,char* ps[]) 
{  
	
        COptions Options(pn,ps);
	Options.Parse("-in"    	,inputFileName   ," Input File         "  ,string("Batty.z80"));
	Options.Parse("-d"    	,inputFileNameS   ," Input File  Snap       "  ,string(""));
	Options.Parse("-v"    	,bDebugMode   ," debug mode        "  ,false);
	if(!Options.IsOk()){Options.Usage("Parse Error");return 0;}
	int win;
	glutInitWindowSize (10,10);
	glutInitWindowPosition (0,0);
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE| GLUT_DEPTH);
	glutInit(&pn,ps);
	win = glutCreateWindow ("viewer");
	
	//~ glutInit(&pn,ps);
	
#ifdef __WIN32
// new version
 //~ unsigned int fpu_oldcw, fpu_cw;
 //~ _controlfp_s(&fpu_cw, 0, 0);
 //~ fpu_oldcw = fpu_cw;
 //~ _controlfp_s(&fpu_cw, _PC_64, _MCW_PC);
 // calculation here
#endif
	//~ handleBase = init_handles();
	//~ set_handles(handleBase);
	try
	{
		
		render = new Render();
		render->runD();
	}	
	catch(const char* mess)
	{
		cout<<"\n catch \n"<<mess;
	}
	delete render;
#ifdef __WIN32
 //~ _controlfp_s(&fpu_cw, fpu_oldcw, _MCW_PC);
#endif
	return 0; 
}
