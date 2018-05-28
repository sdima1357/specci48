SOURCE = main.cpp main_ROM.c z80.c
TSOURCE = coretest.c z80.c
MAIN 	= spec
TMAIN 	= tests/spec_test
RM=-rm -f
ASM    = $(CC) $(CFLAGS) $(INCLUDES) -x	assembler-with-cpp -c  	  	
MASM   = gasp -a
CFLAGS    = -DUNIX -Dx86_64 -Wno-deprecated -Wno-write-strings -fPIC -DTHREAD_SAFE
LFLAGS      =  -L/opt/libjpeg-turbo/lib -L/usr/lib -L/usr/local/lib -L/usr/X11R6/lib/ -L../lib/ -lGL -lpthread -lcrypto -lglut -lGLU -lX11  -lz  
CC       = g++  -Os -fPIC -std=c++0x -pthread -fopenmp -march=native -msse4.2 -mavx -mfpmath=sse -mabm -ffast-math -funroll-loops -DTHREAD_SAFE

.SUFFIXES: .asm .o .c .cpp .s .S .cu .f

OBJ0      := $(SOURCE:.c=.o) 
OBJ1      := $(OBJ0:.cpp=.o) 
OBJ3      := $(OBJ1:.S=.o)
OBJS       := $(OBJ3:.s=.o) 

TOBJS := $(TSOURCE:.c=.o) 


.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $(ADD_FLAGS) -c $<
.S.o:
	$(CC) $(CFLAGS) $(INCLUDES) $(ADD_FLAGS) -x assembler-with-cpp -c $<
.c.o:   
	$(CC) $(CFLAGS) $(INCLUDES) $(ADD_FLAGS) -x c -c $<
.s.o:
	$(ASM) $< -o $@

all:  $(MAIN) $(TMAIN)

$(MAIN):  $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS)  $(LFLAGS) -lspectrum -o $@

$(TMAIN):  $(TOBJS)
	$(CC) $(CFLAGS)  $(TOBJS)  $(LFLAGS) -lspectrum -o $@
	strip -s $(TMAIN)


clean:
	$(RM) *.o *~ $(MAIN)
	$(RM) *.o *~ $(TMAIN)

