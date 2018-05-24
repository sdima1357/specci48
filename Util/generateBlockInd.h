#ifndef generate_H
#define generate_H
#define BLOCKS ((0x10000-0x5B00)/64)
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
#endif
