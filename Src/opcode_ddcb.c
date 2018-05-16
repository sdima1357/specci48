/*LD B, RLC (IX+$)*/
//~ void opcode_ddcb(u8 opcode)
{
	//~ if((bt>=0x40)&&(bt<0x80)) bt|=7;
switch (opcode) 
{
case 0x00:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RLC (IX+$)*/
case 0x01:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RLC (IX+$)*/
case 0x02:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RLC (IX+$)*/
case 0x03:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RLC (IX+$)*/
case 0x04:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RLC (IX+$)*/
case 0x05:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RLC (IX+$)*/
case 0x06:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RLC (IX+$)*/
case 0x07:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RRC (IX+$)*/
case 0x08:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RRC (IX+$)*/
case 0x09:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RRC (IX+$)*/
case 0x0a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RRC (IX+$)*/
case 0x0b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RRC (IX+$)*/
case 0x0c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RRC (IX+$)*/
case 0x0d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RRC (IX+$)*/
case 0x0e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RRC (IX+$)*/
case 0x0f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RL (IX+$)*/
case 0x10:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RL (IX+$)*/
case 0x11:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RL (IX+$)*/
case 0x12:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RL (IX+$)*/
case 0x13:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RL (IX+$)*/
case 0x14:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RL (IX+$)*/
case 0x15:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RL (IX+$)*/
case 0x16:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RL (IX+$)*/
case 0x17:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RR (IX+$)*/
case 0x18:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RR (IX+$)*/
case 0x19:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RR (IX+$)*/
case 0x1a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RR (IX+$)*/
case 0x1b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RR (IX+$)*/
case 0x1c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RR (IX+$)*/
case 0x1d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RR (IX+$)*/
case 0x1e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RR (IX+$)*/
case 0x1f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SLA (IX+$)*/
case 0x20:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SLA (IX+$)*/
case 0x21:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SLA (IX+$)*/
case 0x22:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SLA (IX+$)*/
case 0x23:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SLA (IX+$)*/
case 0x24:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SLA (IX+$)*/
case 0x25:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SLA (IX+$)*/
case 0x26:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SLA (IX+$)*/
case 0x27:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SRA (IX+$)*/
case 0x28:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SRA (IX+$)*/
case 0x29:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SRA (IX+$)*/
case 0x2a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SRA (IX+$)*/
case 0x2b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SRA (IX+$)*/
case 0x2c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SRA (IX+$)*/
case 0x2d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SRA (IX+$)*/
case 0x2e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SRA (IX+$)*/
case 0x2f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SLL (IX+$)*/
case 0x30:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SLL (IX+$)*/
case 0x31:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SLL (IX+$)*/
case 0x32:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SLL (IX+$)*/
case 0x33:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SLL (IX+$)*/
case 0x34:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SLL (IX+$)*/
case 0x35:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SLL (IX+$)*/
case 0x36:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SLL (IX+$)*/
case 0x37:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SRL (IX+$)*/
case 0x38:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SRL (IX+$)*/
case 0x39:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SRL (IX+$)*/
case 0x3a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SRL (IX+$)*/
case 0x3b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SRL (IX+$)*/
case 0x3c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SRL (IX+$)*/
case 0x3d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SRL (IX+$)*/
case 0x3e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SRL (IX+$)*/
case 0x3f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*BIT 0, (IX+$)*/
case 0x40:
case 0x41:
case 0x42:
case 0x43:
case 0x44:
case 0x45:
case 0x46:
case 0x47:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(0, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 1, (IX+$)*/
case 0x48:
case 0x49:
case 0x4a:
case 0x4b:
case 0x4c:
case 0x4d:
case 0x4e:
case 0x4f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(1, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 2, (IX+$)*/
case 0x50:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
case 0x55:
case 0x56:
case 0x57:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(2, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 3, (IX+$)*/
case 0x58:
case 0x59:
case 0x5a:
case 0x5b:
case 0x5c:
case 0x5d:
case 0x5e:
case 0x5f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(3, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 4, (IX+$)*/
case 0x60:
case 0x61:
case 0x62:
case 0x63:
case 0x64:
case 0x65:
case 0x66:
case 0x67:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(4, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 5, (IX+$)*/
case 0x68:
case 0x69:
case 0x6a:
case 0x6b:
case 0x6c:
case 0x6d:
case 0x6e:
case 0x6f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(5, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 6, (IX+$)*/
case 0x70:
case 0x71:
case 0x72:
case 0x73:
case 0x74:
case 0x75:
case 0x76:
case 0x77:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(6, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*BIT 7, (IX+$)*/
case 0x78:
case 0x79:
case 0x7a:
case 0x7b:
case 0x7c:
case 0x7d:
case 0x7e:
case 0x7f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(7, temp8);
	T_WAIT_UNTIL(-3);
	break;

/*LD B, RES 0, (IX+$)*/
case 0x80:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 0, (IX+$)*/
case 0x81:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 0, (IX+$)*/
case 0x82:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 0, (IX+$)*/
case 0x83:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 0, (IX+$)*/
case 0x84:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 0, (IX+$)*/
case 0x85:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 0, (IX+$)*/
case 0x86:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 0, (IX+$)*/
case 0x87:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 1, (IX+$)*/
case 0x88:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 1, (IX+$)*/
case 0x89:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 1, (IX+$)*/
case 0x8a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 1, (IX+$)*/
case 0x8b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 1, (IX+$)*/
case 0x8c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 1, (IX+$)*/
case 0x8d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 1, (IX+$)*/
case 0x8e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 1, (IX+$)*/
case 0x8f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 2, (IX+$)*/
case 0x90:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 2, (IX+$)*/
case 0x91:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 2, (IX+$)*/
case 0x92:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 2, (IX+$)*/
case 0x93:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 2, (IX+$)*/
case 0x94:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 2, (IX+$)*/
case 0x95:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 2, (IX+$)*/
case 0x96:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 2, (IX+$)*/
case 0x97:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 3, (IX+$)*/
case 0x98:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 3, (IX+$)*/
case 0x99:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 3, (IX+$)*/
case 0x9a:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 3, (IX+$)*/
case 0x9b:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 3, (IX+$)*/
case 0x9c:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 3, (IX+$)*/
case 0x9d:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 3, (IX+$)*/
case 0x9e:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 3, (IX+$)*/
case 0x9f:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 4, (IX+$)*/
case 0xa0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 4, (IX+$)*/
case 0xa1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 4, (IX+$)*/
case 0xa2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 4, (IX+$)*/
case 0xa3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 4, (IX+$)*/
case 0xa4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 4, (IX+$)*/
case 0xa5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 4, (IX+$)*/
case 0xa6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 4, (IX+$)*/
case 0xa7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 5, (IX+$)*/
case 0xa8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 5, (IX+$)*/
case 0xa9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 5, (IX+$)*/
case 0xaa:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 5, (IX+$)*/
case 0xab:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 5, (IX+$)*/
case 0xac:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 5, (IX+$)*/
case 0xad:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 5, (IX+$)*/
case 0xae:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 5, (IX+$)*/
case 0xaf:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 6, (IX+$)*/
case 0xb0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 6, (IX+$)*/
case 0xb1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 6, (IX+$)*/
case 0xb2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 6, (IX+$)*/
case 0xb3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 6, (IX+$)*/
case 0xb4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 6, (IX+$)*/
case 0xb5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 6, (IX+$)*/
case 0xb6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 6, (IX+$)*/
case 0xb7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, RES 7, (IX+$)*/
case 0xb8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, RES 7, (IX+$)*/
case 0xb9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, RES 7, (IX+$)*/
case 0xba:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, RES 7, (IX+$)*/
case 0xbb:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, RES 7, (IX+$)*/
case 0xbc:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, RES 7, (IX+$)*/
case 0xbd:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*RES 7, (IX+$)*/
case 0xbe:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, RES 7, (IX+$)*/
case 0xbf:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 0, (IX+$)*/
case 0xc0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 0, (IX+$)*/
case 0xc1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 0, (IX+$)*/
case 0xc2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 0, (IX+$)*/
case 0xc3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 0, (IX+$)*/
case 0xc4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 0, (IX+$)*/
case 0xc5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 0, (IX+$)*/
case 0xc6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 0, (IX+$)*/
case 0xc7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 1, (IX+$)*/
case 0xc8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 1, (IX+$)*/
case 0xc9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 1, (IX+$)*/
case 0xca:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 1, (IX+$)*/
case 0xcb:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 1, (IX+$)*/
case 0xcc:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 1, (IX+$)*/
case 0xcd:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 1, (IX+$)*/
case 0xce:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 1, (IX+$)*/
case 0xcf:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 2, (IX+$)*/
case 0xd0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 2, (IX+$)*/
case 0xd1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 2, (IX+$)*/
case 0xd2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 2, (IX+$)*/
case 0xd3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 2, (IX+$)*/
case 0xd4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 2, (IX+$)*/
case 0xd5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 2, (IX+$)*/
case 0xd6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 2, (IX+$)*/
case 0xd7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 3, (IX+$)*/
case 0xd8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 3, (IX+$)*/
case 0xd9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 3, (IX+$)*/
case 0xda:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 3, (IX+$)*/
case 0xdb:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 3, (IX+$)*/
case 0xdc:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 3, (IX+$)*/
case 0xdd:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 3, (IX+$)*/
case 0xde:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 3, (IX+$)*/
case 0xdf:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 4, (IX+$)*/
case 0xe0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 4, (IX+$)*/
case 0xe1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 4, (IX+$)*/
case 0xe2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 4, (IX+$)*/
case 0xe3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 4, (IX+$)*/
case 0xe4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 4, (IX+$)*/
case 0xe5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 4, (IX+$)*/
case 0xe6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 4, (IX+$)*/
case 0xe7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 5, (IX+$)*/
case 0xe8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 5, (IX+$)*/
case 0xe9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 5, (IX+$)*/
case 0xea:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 5, (IX+$)*/
case 0xeb:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 5, (IX+$)*/
case 0xec:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 5, (IX+$)*/
case 0xed:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 5, (IX+$)*/
case 0xee:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 5, (IX+$)*/
case 0xef:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 6, (IX+$)*/
case 0xf0:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 6, (IX+$)*/
case 0xf1:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 6, (IX+$)*/
case 0xf2:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 6, (IX+$)*/
case 0xf3:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 6, (IX+$)*/
case 0xf4:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 6, (IX+$)*/
case 0xf5:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 6, (IX+$)*/
case 0xf6:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 6, (IX+$)*/
case 0xf7:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD B, SET 7, (IX+$)*/
case 0xf8:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(B, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD C, SET 7, (IX+$)*/
case 0xf9:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(C, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD D, SET 7, (IX+$)*/
case 0xfa:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(D, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD E, SET 7, (IX+$)*/
case 0xfb:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(E, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD H, SET 7, (IX+$)*/
case 0xfc:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(H, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD L, SET 7, (IX+$)*/
case 0xfd:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(L, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*SET 7, (IX+$)*/
case 0xfe:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;

/*LD A, SET 7, (IX+$)*/
case 0xff:
	//MEMPTR=(IX+d.s);
	//u8 temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(A, temp8);
	//WRITE_BYTE(IX+d.s, temp8);
	EMPTY;
	break;
default:
	T_WAIT_UNTIL(-19);
}
}
/*
static void (*opcode_ddcb[0x100])(void)={
	op_DDCB_0x00, op_DDCB_0x01, op_DDCB_0x02, op_DDCB_0x03, op_DDCB_0x04, op_DDCB_0x05, op_DDCB_0x06, op_DDCB_0x07, op_DDCB_0x08, op_DDCB_0x09, op_DDCB_0x0a, op_DDCB_0x0b, op_DDCB_0x0c, op_DDCB_0x0d, op_DDCB_0x0e, op_DDCB_0x0f,
	op_DDCB_0x10, op_DDCB_0x11, op_DDCB_0x12, op_DDCB_0x13, op_DDCB_0x14, op_DDCB_0x15, op_DDCB_0x16, op_DDCB_0x17, op_DDCB_0x18, op_DDCB_0x19, op_DDCB_0x1a, op_DDCB_0x1b, op_DDCB_0x1c, op_DDCB_0x1d, op_DDCB_0x1e, op_DDCB_0x1f,
	op_DDCB_0x20, op_DDCB_0x21, op_DDCB_0x22, op_DDCB_0x23, op_DDCB_0x24, op_DDCB_0x25, op_DDCB_0x26, op_DDCB_0x27, op_DDCB_0x28, op_DDCB_0x29, op_DDCB_0x2a, op_DDCB_0x2b, op_DDCB_0x2c, op_DDCB_0x2d, op_DDCB_0x2e, op_DDCB_0x2f,
	op_DDCB_0x30, op_DDCB_0x31, op_DDCB_0x32, op_DDCB_0x33, op_DDCB_0x34, op_DDCB_0x35, op_DDCB_0x36, op_DDCB_0x37, op_DDCB_0x38, op_DDCB_0x39, op_DDCB_0x3a, op_DDCB_0x3b, op_DDCB_0x3c, op_DDCB_0x3d, op_DDCB_0x3e, op_DDCB_0x3f,
	op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f,
	op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f,
	op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f,
	op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f,
	op_DDCB_0x80, op_DDCB_0x81, op_DDCB_0x82, op_DDCB_0x83, op_DDCB_0x84, op_DDCB_0x85, op_DDCB_0x86, op_DDCB_0x87, op_DDCB_0x88, op_DDCB_0x89, op_DDCB_0x8a, op_DDCB_0x8b, op_DDCB_0x8c, op_DDCB_0x8d, op_DDCB_0x8e, op_DDCB_0x8f,
	op_DDCB_0x90, op_DDCB_0x91, op_DDCB_0x92, op_DDCB_0x93, op_DDCB_0x94, op_DDCB_0x95, op_DDCB_0x96, op_DDCB_0x97, op_DDCB_0x98, op_DDCB_0x99, op_DDCB_0x9a, op_DDCB_0x9b, op_DDCB_0x9c, op_DDCB_0x9d, op_DDCB_0x9e, op_DDCB_0x9f,
	op_DDCB_0xa0, op_DDCB_0xa1, op_DDCB_0xa2, op_DDCB_0xa3, op_DDCB_0xa4, op_DDCB_0xa5, op_DDCB_0xa6, op_DDCB_0xa7, op_DDCB_0xa8, op_DDCB_0xa9, op_DDCB_0xaa, op_DDCB_0xab, op_DDCB_0xac, op_DDCB_0xad, op_DDCB_0xae, op_DDCB_0xaf,
	op_DDCB_0xb0, op_DDCB_0xb1, op_DDCB_0xb2, op_DDCB_0xb3, op_DDCB_0xb4, op_DDCB_0xb5, op_DDCB_0xb6, op_DDCB_0xb7, op_DDCB_0xb8, op_DDCB_0xb9, op_DDCB_0xba, op_DDCB_0xbb, op_DDCB_0xbc, op_DDCB_0xbd, op_DDCB_0xbe, op_DDCB_0xbf,
	op_DDCB_0xc0, op_DDCB_0xc1, op_DDCB_0xc2, op_DDCB_0xc3, op_DDCB_0xc4, op_DDCB_0xc5, op_DDCB_0xc6, op_DDCB_0xc7, op_DDCB_0xc8, op_DDCB_0xc9, op_DDCB_0xca, op_DDCB_0xcb, op_DDCB_0xcc, op_DDCB_0xcd, op_DDCB_0xce, op_DDCB_0xcf,
	op_DDCB_0xd0, op_DDCB_0xd1, op_DDCB_0xd2, op_DDCB_0xd3, op_DDCB_0xd4, op_DDCB_0xd5, op_DDCB_0xd6, op_DDCB_0xd7, op_DDCB_0xd8, op_DDCB_0xd9, op_DDCB_0xda, op_DDCB_0xdb, op_DDCB_0xdc, op_DDCB_0xdd, op_DDCB_0xde, op_DDCB_0xdf,
	op_DDCB_0xe0, op_DDCB_0xe1, op_DDCB_0xe2, op_DDCB_0xe3, op_DDCB_0xe4, op_DDCB_0xe5, op_DDCB_0xe6, op_DDCB_0xe7, op_DDCB_0xe8, op_DDCB_0xe9, op_DDCB_0xea, op_DDCB_0xeb, op_DDCB_0xec, op_DDCB_0xed, op_DDCB_0xee, op_DDCB_0xef,
	op_DDCB_0xf0, op_DDCB_0xf1, op_DDCB_0xf2, op_DDCB_0xf3, op_DDCB_0xf4, op_DDCB_0xf5, op_DDCB_0xf6, op_DDCB_0xf7, op_DDCB_0xf8, op_DDCB_0xf9, op_DDCB_0xfa, op_DDCB_0xfb, op_DDCB_0xfc, op_DDCB_0xfd, op_DDCB_0xfe, op_DDCB_0xff
};
*/