//~ void opcode_dd(u8 bt)
{
switch (opcode) 
{
/*ADD IX, BC*/
case 0x09:
	ADD16(IX, BC);
	T_WAIT_UNTIL(11);
break;

/*ADD IX, DE*/
case 0x19:
	ADD16(IX, DE);
	T_WAIT_UNTIL(11);
break;

/*LD IX, @*/
case 0x21:
	nn=NEXT_WORD;
	LD16(IX, nn);
	T_WAIT_UNTIL(10);
break;

/*LD (@), IX*/
case 0x22:
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, IX, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
break;

/*INC IX*/
case 0x23:
	INC16(IX);
	T_WAIT_UNTIL(6);
break;

/*INC IXH*/
case 0x24:
	INC(IXH);
	T_WAIT_UNTIL(4);
break;

/*DEC IXH*/
case 0x25:
	DEC(IXH);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, #*/
case 0x26:
	n=NEXT_BYTE;
	LD(IXH, n);
	T_WAIT_UNTIL(7);
break;

/*ADD IX, IX*/
case 0x29:
	ADD16(IX, IX);
	T_WAIT_UNTIL(11);
break;

/*LD IX, (@)*/
case 0x2a:
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(IX, temp16, nn);
	T_WAIT_UNTIL(16);
break;

/*DEC IX*/
case 0x2b:
	DEC16(IX);
	T_WAIT_UNTIL(6);
break;

/*INC IXL*/
case 0x2c:
	INC(IXL);
	T_WAIT_UNTIL(4);
break;

/*DEC IXL*/
case 0x2d:
	DEC(IXL);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, #*/
case 0x2e:
	n=NEXT_BYTE;
	LD(IXL, n);
	T_WAIT_UNTIL(7);
break;

/*INC (IX+$)*/
case 0x34:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	INC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
break;

/*DEC (IX+$)*/
case 0x35:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	DEC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
break;

/*LD (IX+$), #*/
case 0x36:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	n=NEXT_BYTE;
	LD(n, n);
	WRITE_BYTE(IX+d.s, n);
	T_WAIT_UNTIL(15);
break;

/*ADD IX, SP*/
case 0x39:
	ADD16(IX, SP);
	T_WAIT_UNTIL(11);
break;

/*LD B, IXH*/
case 0x44:
	LD(B, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD B, IXL*/
case 0x45:
	LD(B, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD B, (IX+$)*/
case 0x46:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(B, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD C, IXH*/
case 0x4c:
	LD(C, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD C, IXL*/
case 0x4d:
	LD(C, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD C, (IX+$)*/
case 0x4e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(C, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD D, IXH*/
case 0x54:
	LD(D, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD D, IXL*/
case 0x55:
	LD(D, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD D, (IX+$)*/
case 0x56:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(D, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD E, IXH*/
case 0x5c:
	LD(E, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD E, IXL*/
case 0x5d:
	LD(E, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD E, (IX+$)*/
case 0x5e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(E, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD IXH, B*/
case 0x60:
	LD(IXH, B);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, C*/
case 0x61:
	LD(IXH, C);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, D*/
case 0x62:
	LD(IXH, D);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, E*/
case 0x63:
	LD(IXH, E);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, IXH*/
case 0x64:
	LD(IXH, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD IXH, IXL*/
case 0x65:
	LD(IXH, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD H, (IX+$)*/
case 0x66:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(H, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD IXH, A*/
case 0x67:
	LD(IXH, A);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, B*/
case 0x68:
	LD(IXL, B);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, C*/
case 0x69:
	LD(IXL, C);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, D*/
case 0x6a:
	LD(IXL, D);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, E*/
case 0x6b:
	LD(IXL, E);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, IXH*/
case 0x6c:
	LD(IXL, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD IXL, IXL*/
case 0x6d:
	LD(IXL, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD L, (IX+$)*/
case 0x6e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(L, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD IXL, A*/
case 0x6f:
	LD(IXL, A);
	T_WAIT_UNTIL(4);
break;

/*LD (IX+$), B*/
case 0x70:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, B);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), C*/
case 0x71:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, C);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), D*/
case 0x72:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, D);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), E*/
case 0x73:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, E);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), H*/
case 0x74:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, H);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), L*/
case 0x75:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, L);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD (IX+$), A*/
case 0x77:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, A);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
break;

/*LD A, IXH*/
case 0x7c:
	LD(A, IXH);
	T_WAIT_UNTIL(4);
break;

/*LD A, IXL*/
case 0x7d:
	LD(A, IXL);
	T_WAIT_UNTIL(4);
break;

/*LD A, (IX+$)*/
case 0x7e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(A, temp8);
	T_WAIT_UNTIL(15);
break;

/*ADD A, IXH*/
case 0x84:
	ADD(A, IXH);
	T_WAIT_UNTIL(4);
break;

/*ADD A, IXL*/
case 0x85:
	ADD(A, IXL);
	T_WAIT_UNTIL(4);
break;

/*ADD A, (IX+$)*/
case 0x86:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	ADD(A, temp8);
	T_WAIT_UNTIL(15);
break;

/*ADDC A, IXH*/
case 0x8c:
	ADDC(A, IXH);
	T_WAIT_UNTIL(4);
break;

/*ADDC A, IXL*/
case 0x8d:
	ADDC(A, IXL);
	T_WAIT_UNTIL(4);
break;

/*ADDC A, (IX+$)*/
case 0x8e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	ADDC(A, temp8);
	T_WAIT_UNTIL(15);
break;

/*SUB IXH*/
case 0x94:
	SUB(IXH);
	T_WAIT_UNTIL(4);
break;

/*SUB IXL*/
case 0x95:
	SUB(IXL);
	T_WAIT_UNTIL(4);
break;

/*SUB (IX+$)*/
case 0x96:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SUB(temp8);
	T_WAIT_UNTIL(15);
break;

/*SUBC A, IXH*/
case 0x9c:
	SUBC(A, IXH);
	T_WAIT_UNTIL(4);
break;

/*SUBC A, IXL*/
case 0x9d:
	SUBC(A, IXL);
	T_WAIT_UNTIL(4);
break;

/*SUBC A, (IX+$)*/
case 0x9e:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SUBC(A, temp8);
	T_WAIT_UNTIL(15);
break;

/*AND IXH*/
case 0xa4:
	AND(IXH);
	T_WAIT_UNTIL(4);
break;

/*AND IXL*/
case 0xa5:
	AND(IXL);
	T_WAIT_UNTIL(4);
break;

/*AND (IX+$)*/
case 0xa6:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	AND(temp8);
	T_WAIT_UNTIL(15);
break;

/*XOR IXH*/
case 0xac:
	XOR(IXH);
	T_WAIT_UNTIL(4);
break;

/*XOR IXL*/
case 0xad:
	XOR(IXL);
	T_WAIT_UNTIL(4);
break;

/*XOR (IX+$)*/
case 0xae:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	XOR(temp8);
	T_WAIT_UNTIL(15);
break;

/*OR IXH*/
case 0xb4:
	OR(IXH);
	T_WAIT_UNTIL(4);
break;

/*OR IXL*/
case 0xb5:
	OR(IXL);
	T_WAIT_UNTIL(4);
break;

/*OR (IX+$)*/
case 0xb6:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	OR(temp8);
	T_WAIT_UNTIL(15);
break;

/*CP IXH*/
case 0xbc:
	CP(IXH);
	T_WAIT_UNTIL(4);
break;

/*CP IXL*/
case 0xbd:
	CP(IXL);
	T_WAIT_UNTIL(4);
break;

/*CP (IX+$)*/
case 0xbe:
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	CP(temp8);
	T_WAIT_UNTIL(15);
break;


/*POP IX*/
case 0xe1:
	POP(IX);
	T_WAIT_UNTIL(10);
break;

/*EX (SP), IX*/
case 0xe3:
	temp16=READ_WORD(SP);
	EX_MPTR(temp16, IX);
	WRITE_WORD(SP, temp16);
	T_WAIT_UNTIL(19);
break;

/*PUSH IX*/
case 0xe5:
	PUSH(IX);
	T_WAIT_UNTIL(11);
break;

/*JP IX*/
case 0xe9:
	JP_NO_MPTR(IX);
	T_WAIT_UNTIL(4);
break;

/*LD SP, IX*/
case 0xf9:
	LD16(SP, IX);
	T_WAIT_UNTIL(6);
break;

/*NONI*/
default :
	T_WAIT_UNTIL(4);
break;
}
}
/*
static void (*opcode_dd[0x100])(void)={
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x09, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x19, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , op_DD_0x21, op_DD_0x22, op_DD_0x23, op_DD_0x24, op_DD_0x25, op_DD_0x26, noni_DD   , noni_DD   , op_DD_0x29, op_DD_0x2a, op_DD_0x2b, op_DD_0x2c, op_DD_0x2d, op_DD_0x2e, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x34, op_DD_0x35, op_DD_0x36, noni_DD   , noni_DD   , op_DD_0x39, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x44, op_DD_0x45, op_DD_0x46, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x4c, op_DD_0x4d, op_DD_0x4e, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x54, op_DD_0x55, op_DD_0x56, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x5c, op_DD_0x5d, op_DD_0x5e, noni_DD   ,
	op_DD_0x60, op_DD_0x61, op_DD_0x62, op_DD_0x63, op_DD_0x64, op_DD_0x65, op_DD_0x66, op_DD_0x67, op_DD_0x68, op_DD_0x69, op_DD_0x6a, op_DD_0x6b, op_DD_0x6c, op_DD_0x6d, op_DD_0x6e, op_DD_0x6f,
	op_DD_0x70, op_DD_0x71, op_DD_0x72, op_DD_0x73, op_DD_0x74, op_DD_0x75, noni_DD   , op_DD_0x77, noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x7c, op_DD_0x7d, op_DD_0x7e, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x84, op_DD_0x85, op_DD_0x86, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x8c, op_DD_0x8d, op_DD_0x8e, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x94, op_DD_0x95, op_DD_0x96, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0x9c, op_DD_0x9d, op_DD_0x9e, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0xa4, op_DD_0xa5, op_DD_0xa6, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0xac, op_DD_0xad, op_DD_0xae, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0xb4, op_DD_0xb5, op_DD_0xb6, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0xbc, op_DD_0xbd, op_DD_0xbe, noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , op_DD_0xe1, noni_DD   , op_DD_0xe3, noni_DD   , op_DD_0xe5, noni_DD   , noni_DD   , noni_DD   , op_DD_0xe9, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   ,
	noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , op_DD_0xf9, noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD   , noni_DD
};
*/