//~ void opcode_cb(u8 bt)
{
switch (opcode) 
{
/*RLC B*/
case 0x00:
	RLC(B);
	EMPTY;
break;
/*RLC C*/
case 0x01:
	RLC(C);
	EMPTY;
break;
/*RLC D*/
case 0x02:
	RLC(D);
	EMPTY;
break;
/*RLC E*/
case 0x03:
	RLC(E);
	EMPTY;
break;
/*RLC H*/
case 0x04:
	RLC(H);
	EMPTY;
break;
/*RLC L*/
case 0x05:
	RLC(L);
	EMPTY;
break;
/*RLC (HL)*/
case 0x06:
	temp8=READ_BYTE(HL);
	RLC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RLC A*/
case 0x07:
	RLC(A);
	EMPTY;
break;
/*RRC B*/
case 0x08:
	RRC(B);
	EMPTY;
break;
/*RRC C*/
case 0x09:
	RRC(C);
	EMPTY;
break;
/*RRC D*/
case 0x0a:
	RRC(D);
	EMPTY;
break;
/*RRC E*/
case 0x0b:
	RRC(E);
	EMPTY;
break;
/*RRC H*/
case 0x0c:
	RRC(H);
	EMPTY;
break;
/*RRC L*/
case 0x0d:
	RRC(L);
	EMPTY;
break;
/*RRC (HL)*/
case 0x0e:
	temp8=READ_BYTE(HL);
	RRC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RRC A*/
case 0x0f:
	RRC(A);
	EMPTY;
break;
/*RL B*/
case 0x10:
	RL(B);
	EMPTY;
break;
/*RL C*/
case 0x11:
	RL(C);
	EMPTY;
break;
/*RL D*/
case 0x12:
	RL(D);
	EMPTY;
break;
/*RL E*/
case 0x13:
	RL(E);
	EMPTY;
break;
/*RL H*/
case 0x14:
	RL(H);
	EMPTY;
break;
/*RL L*/
case 0x15:
	RL(L);
	EMPTY;
break;
/*RL (HL)*/
case 0x16:
	temp8=READ_BYTE(HL);
	RL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RL A*/
case 0x17:
	RL(A);
	EMPTY;
break;
/*RR B*/
case 0x18:
	RR(B);
	EMPTY;
break;
/*RR C*/
case 0x19:
	RR(C);
	EMPTY;
break;
/*RR D*/
case 0x1a:
	RR(D);
	EMPTY;
break;
/*RR E*/
case 0x1b:
	RR(E);
	EMPTY;
break;
/*RR H*/
case 0x1c:
	RR(H);
	EMPTY;
break;
/*RR L*/
case 0x1d:
	RR(L);
	EMPTY;
break;
/*RR (HL)*/
case 0x1e:
	temp8=READ_BYTE(HL);
	RR(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RR A*/
case 0x1f:
	RR(A);
	EMPTY;
break;
/*SLA B*/
case 0x20:
	SLA(B);
	EMPTY;
break;
/*SLA C*/
case 0x21:
	SLA(C);
	EMPTY;
break;
/*SLA D*/
case 0x22:
	SLA(D);
	EMPTY;
break;
/*SLA E*/
case 0x23:
	SLA(E);
	EMPTY;
break;
/*SLA H*/
case 0x24:
	SLA(H);
	EMPTY;
break;
/*SLA L*/
case 0x25:
	SLA(L);
	EMPTY;
break;
/*SLA (HL)*/
case 0x26:
	temp8=READ_BYTE(HL);
	SLA(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SLA A*/
case 0x27:
	SLA(A);
	EMPTY;
break;
/*SRA B*/
case 0x28:
	SRA(B);
	EMPTY;
break;
/*SRA C*/
case 0x29:
	SRA(C);
	EMPTY;
break;
/*SRA D*/
case 0x2a:
	SRA(D);
	EMPTY;
break;
/*SRA E*/
case 0x2b:
	SRA(E);
	EMPTY;
break;
/*SRA H*/
case 0x2c:
	SRA(H);
	EMPTY;
break;
/*SRA L*/
case 0x2d:
	SRA(L);
	EMPTY;
break;
/*SRA (HL)*/
case 0x2e:
	temp8=READ_BYTE(HL);
	SRA(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SRA A*/
case 0x2f:
	SRA(A);
	EMPTY;
break;
/*SLL B*/
case 0x30:
	SLL(B);
	EMPTY;
break;
/*SLL C*/
case 0x31:
	SLL(C);
	EMPTY;
break;
/*SLL D*/
case 0x32:
	SLL(D);
	EMPTY;
break;
/*SLL E*/
case 0x33:
	SLL(E);
	EMPTY;
break;
/*SLL H*/
case 0x34:
	SLL(H);
	EMPTY;
break;
/*SLL L*/
case 0x35:
	SLL(L);
	EMPTY;
break;
/*SLL (HL)*/
case 0x36:
	temp8=READ_BYTE(HL);
	SLL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SLL A*/
case 0x37:
	SLL(A);
	EMPTY;
break;
/*SRL B*/
case 0x38:
	SRL(B);
	EMPTY;
break;
/*SRL C*/
case 0x39:
	SRL(C);
	EMPTY;
break;
/*SRL D*/
case 0x3a:
	SRL(D);
	EMPTY;
break;
/*SRL E*/
case 0x3b:
	SRL(E);
	EMPTY;
break;
/*SRL H*/
case 0x3c:
	SRL(H);
	EMPTY;
break;
/*SRL L*/
case 0x3d:
	SRL(L);
	EMPTY;
break;
/*SRL (HL)*/
case 0x3e:
	temp8=READ_BYTE(HL);
	SRL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SRL A*/
case 0x3f:
	SRL(A);
	EMPTY;
break;
/*BIT 0, B*/
case 0x40:
	BIT(0, B);
	EMPTY;
break;
/*BIT 0, C*/
case 0x41:
	BIT(0, C);
	EMPTY;
break;
/*BIT 0, D*/
case 0x42:
	BIT(0, D);
	EMPTY;
break;
/*BIT 0, E*/
case 0x43:
	BIT(0, E);
	EMPTY;
break;
/*BIT 0, H*/
case 0x44:
	BIT(0, H);
	EMPTY;
break;
/*BIT 0, L*/
case 0x45:
	BIT(0, L);
	EMPTY;
break;
/*BIT 0, (HL)*/
case 0x46:
	temp8=READ_BYTE(HL);
	BIT_MPTR(0, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 0, A*/
case 0x47:
	BIT(0, A);
	EMPTY;
break;
/*BIT 1, B*/
case 0x48:
	BIT(1, B);
	EMPTY;
break;
/*BIT 1, C*/
case 0x49:
	BIT(1, C);
	EMPTY;
break;
/*BIT 1, D*/
case 0x4a:
	BIT(1, D);
	EMPTY;
break;
/*BIT 1, E*/
case 0x4b:
	BIT(1, E);
	EMPTY;
break;
/*BIT 1, H*/
case 0x4c:
	BIT(1, H);
	EMPTY;
break;
/*BIT 1, L*/
case 0x4d:
	BIT(1, L);
	EMPTY;
break;
/*BIT 1, (HL)*/
case 0x4e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(1, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 1, A*/
case 0x4f:
	BIT(1, A);
	EMPTY;
break;
/*BIT 2, B*/
case 0x50:
	BIT(2, B);
	EMPTY;
break;
/*BIT 2, C*/
case 0x51:
	BIT(2, C);
	EMPTY;
break;
/*BIT 2, D*/
case 0x52:
	BIT(2, D);
	EMPTY;
break;
/*BIT 2, E*/
case 0x53:
	BIT(2, E);
	EMPTY;
break;
/*BIT 2, H*/
case 0x54:
	BIT(2, H);
	EMPTY;
break;
/*BIT 2, L*/
case 0x55:
	BIT(2, L);
	EMPTY;
break;
/*BIT 2, (HL)*/
case 0x56:
	temp8=READ_BYTE(HL);
	BIT_MPTR(2, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 2, A*/
case 0x57:
	BIT(2, A);
	EMPTY;
break;
/*BIT 3, B*/
case 0x58:
	BIT(3, B);
	EMPTY;
break;
/*BIT 3, C*/
case 0x59:
	BIT(3, C);
	EMPTY;
break;
/*BIT 3, D*/
case 0x5a:
	BIT(3, D);
	EMPTY;
break;
/*BIT 3, E*/
case 0x5b:
	BIT(3, E);
	EMPTY;
break;
/*BIT 3, H*/
case 0x5c:
	BIT(3, H);
	EMPTY;
break;
/*BIT 3, L*/
case 0x5d:
	BIT(3, L);
	EMPTY;
break;
/*BIT 3, (HL)*/
case 0x5e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(3, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 3, A*/
case 0x5f:
	BIT(3, A);
	EMPTY;
break;
/*BIT 4, B*/
case 0x60:
	BIT(4, B);
	EMPTY;
break;
/*BIT 4, C*/
case 0x61:
	BIT(4, C);
	EMPTY;
break;
/*BIT 4, D*/
case 0x62:
	BIT(4, D);
	EMPTY;
break;
/*BIT 4, E*/
case 0x63:
	BIT(4, E);
	EMPTY;
break;
/*BIT 4, H*/
case 0x64:
	BIT(4, H);
	EMPTY;
break;
/*BIT 4, L*/
case 0x65:
	BIT(4, L);
	EMPTY;
break;
/*BIT 4, (HL)*/
case 0x66:
	temp8=READ_BYTE(HL);
	BIT_MPTR(4, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 4, A*/
case 0x67:
	BIT(4, A);
	EMPTY;
break;
/*BIT 5, B*/
case 0x68:
	BIT(5, B);
	EMPTY;
break;
/*BIT 5, C*/
case 0x69:
	BIT(5, C);
	EMPTY;
break;
/*BIT 5, D*/
case 0x6a:
	BIT(5, D);
	EMPTY;
break;
/*BIT 5, E*/
case 0x6b:
	BIT(5, E);
	EMPTY;
break;
/*BIT 5, H*/
case 0x6c:
	BIT(5, H);
	EMPTY;
break;
/*BIT 5, L*/
case 0x6d:
	BIT(5, L);
	EMPTY;
break;
/*BIT 5, (HL)*/
case 0x6e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(5, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 5, A*/
case 0x6f:
	BIT(5, A);
	EMPTY;
break;
/*BIT 6, B*/
case 0x70:
	BIT(6, B);
	EMPTY;
break;
/*BIT 6, C*/
case 0x71:
	BIT(6, C);
	EMPTY;
break;
/*BIT 6, D*/
case 0x72:
	BIT(6, D);
	EMPTY;
break;
/*BIT 6, E*/
case 0x73:
	BIT(6, E);
	EMPTY;
break;
/*BIT 6, H*/
case 0x74:
	BIT(6, H);
	EMPTY;
break;
/*BIT 6, L*/
case 0x75:
	BIT(6, L);
	EMPTY;
break;
/*BIT 6, (HL)*/
case 0x76:
	temp8=READ_BYTE(HL);
	BIT_MPTR(6, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 6, A*/
case 0x77:
	BIT(6, A);
	EMPTY;
break;
/*BIT 7, B*/
case 0x78:
	BIT(7, B);
	EMPTY;
break;
/*BIT 7, C*/
case 0x79:
	BIT(7, C);
	EMPTY;
break;
/*BIT 7, D*/
case 0x7a:
	BIT(7, D);
	EMPTY;
break;
/*BIT 7, E*/
case 0x7b:
	BIT(7, E);
	EMPTY;
break;
/*BIT 7, H*/
case 0x7c:
	BIT(7, H);
	EMPTY;
break;
/*BIT 7, L*/
case 0x7d:
	BIT(7, L);
	EMPTY;
break;
/*BIT 7, (HL)*/
case 0x7e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(7, temp8);
	T_WAIT_UNTIL(8-4);
break;
/*BIT 7, A*/
case 0x7f:
	BIT(7, A);
	EMPTY;
break;
/*RES 0, B*/
case 0x80:
	RES(0, B);
	EMPTY;
break;
/*RES 0, C*/
case 0x81:
	RES(0, C);
	EMPTY;
break;
/*RES 0, D*/
case 0x82:
	RES(0, D);
	EMPTY;
break;
/*RES 0, E*/
case 0x83:
	RES(0, E);
	EMPTY;
break;
/*RES 0, H*/
case 0x84:
	RES(0, H);
	EMPTY;
break;
/*RES 0, L*/
case 0x85:
	RES(0, L);
	EMPTY;
break;
/*RES 0, (HL)*/
case 0x86:
	temp8=READ_BYTE(HL);
	RES(0, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 0, A*/
case 0x87:
	RES(0, A);
	EMPTY;
break;
/*RES 1, B*/
case 0x88:
	RES(1, B);
	EMPTY;
break;
/*RES 1, C*/
case 0x89:
	RES(1, C);
	EMPTY;
break;
/*RES 1, D*/
case 0x8a:
	RES(1, D);
	EMPTY;
break;
/*RES 1, E*/
case 0x8b:
	RES(1, E);
	EMPTY;
break;
/*RES 1, H*/
case 0x8c:
	RES(1, H);
	EMPTY;
break;
/*RES 1, L*/
case 0x8d:
	RES(1, L);
	EMPTY;
break;
/*RES 1, (HL)*/
case 0x8e:
	temp8=READ_BYTE(HL);
	RES(1, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 1, A*/
case 0x8f:
	RES(1, A);
	EMPTY;
break;
/*RES 2, B*/
case 0x90:
	RES(2, B);
	EMPTY;
break;
/*RES 2, C*/
case 0x91:
	RES(2, C);
	EMPTY;
break;
/*RES 2, D*/
case 0x92:
	RES(2, D);
	EMPTY;
break;
/*RES 2, E*/
case 0x93:
	RES(2, E);
	EMPTY;
break;
/*RES 2, H*/
case 0x94:
	RES(2, H);
	EMPTY;
break;
/*RES 2, L*/
case 0x95:
	RES(2, L);
	EMPTY;
break;
/*RES 2, (HL)*/
case 0x96:
	temp8=READ_BYTE(HL);
	RES(2, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 2, A*/
case 0x97:
	RES(2, A);
	EMPTY;
break;
/*RES 3, B*/
case 0x98:
	RES(3, B);
	EMPTY;
break;
/*RES 3, C*/
case 0x99:
	RES(3, C);
	EMPTY;
break;
/*RES 3, D*/
case 0x9a:
	RES(3, D);
	EMPTY;
break;
/*RES 3, E*/
case 0x9b:
	RES(3, E);
	EMPTY;
break;
/*RES 3, H*/
case 0x9c:
	RES(3, H);
	EMPTY;
break;
/*RES 3, L*/
case 0x9d:
	RES(3, L);
	EMPTY;
break;
/*RES 3, (HL)*/
case 0x9e:
	temp8=READ_BYTE(HL);
	RES(3, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 3, A*/
case 0x9f:
	RES(3, A);
	EMPTY;
break;
/*RES 4, B*/
case 0xa0:
	RES(4, B);
	EMPTY;
break;
/*RES 4, C*/
case 0xa1:
	RES(4, C);
	EMPTY;
break;
/*RES 4, D*/
case 0xa2:
	RES(4, D);
	EMPTY;
break;
/*RES 4, E*/
case 0xa3:
	RES(4, E);
	EMPTY;
break;
/*RES 4, H*/
case 0xa4:
	RES(4, H);
	EMPTY;
break;
/*RES 4, L*/
case 0xa5:
	RES(4, L);
	EMPTY;
break;
/*RES 4, (HL)*/
case 0xa6:
	temp8=READ_BYTE(HL);
	RES(4, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 4, A*/
case 0xa7:
	RES(4, A);
	EMPTY;
break;
/*RES 5, B*/
case 0xa8:
	RES(5, B);
	EMPTY;
break;
/*RES 5, C*/
case 0xa9:
	RES(5, C);
	EMPTY;
break;
/*RES 5, D*/
case 0xaa:
	RES(5, D);
	EMPTY;
break;
/*RES 5, E*/
case 0xab:
	RES(5, E);
	EMPTY;
break;
/*RES 5, H*/
case 0xac:
	RES(5, H);
	EMPTY;
break;
/*RES 5, L*/
case 0xad:
	RES(5, L);
	EMPTY;
break;
/*RES 5, (HL)*/
case 0xae:
	temp8=READ_BYTE(HL);
	RES(5, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 5, A*/
case 0xaf:
	RES(5, A);
	EMPTY;
break;
/*RES 6, B*/
case 0xb0:
	RES(6, B);
	EMPTY;
break;
/*RES 6, C*/
case 0xb1:
	RES(6, C);
	EMPTY;
break;
/*RES 6, D*/
case 0xb2:
	RES(6, D);
	EMPTY;
break;
/*RES 6, E*/
case 0xb3:
	RES(6, E);
	EMPTY;
break;
/*RES 6, H*/
case 0xb4:
	RES(6, H);
	EMPTY;
break;
/*RES 6, L*/
case 0xb5:
	RES(6, L);
	EMPTY;
break;
/*RES 6, (HL)*/
case 0xb6:
	temp8=READ_BYTE(HL);
	RES(6, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 6, A*/
case 0xb7:
	RES(6, A);
	EMPTY;
break;
/*RES 7, B*/
case 0xb8:
	RES(7, B);
	EMPTY;
break;
/*RES 7, C*/
case 0xb9:
	RES(7, C);
	EMPTY;
break;
/*RES 7, D*/
case 0xba:
	RES(7, D);
	EMPTY;
break;
/*RES 7, E*/
case 0xbb:
	RES(7, E);
	EMPTY;
break;
/*RES 7, H*/
case 0xbc:
	RES(7, H);
	EMPTY;
break;
/*RES 7, L*/
case 0xbd:
	RES(7, L);
	EMPTY;
break;
/*RES 7, (HL)*/
case 0xbe:
	temp8=READ_BYTE(HL);
	RES(7, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*RES 7, A*/
case 0xbf:
	RES(7, A);
	EMPTY;
break;
/*SET 0, B*/
case 0xc0:
	SET(0, B);
	EMPTY;
break;
/*SET 0, C*/
case 0xc1:
	SET(0, C);
	EMPTY;
break;
/*SET 0, D*/
case 0xc2:
	SET(0, D);
	EMPTY;
break;
/*SET 0, E*/
case 0xc3:
	SET(0, E);
	EMPTY;
break;
/*SET 0, H*/
case 0xc4:
	SET(0, H);
	EMPTY;
break;
/*SET 0, L*/
case 0xc5:
	SET(0, L);
	EMPTY;
break;
/*SET 0, (HL)*/
case 0xc6:
	temp8=READ_BYTE(HL);
	SET(0, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 0, A*/
case 0xc7:
	SET(0, A);
	EMPTY;
break;
/*SET 1, B*/
case 0xc8:
	SET(1, B);
	EMPTY;
break;
/*SET 1, C*/
case 0xc9:
	SET(1, C);
	EMPTY;
break;
/*SET 1, D*/
case 0xca:
	SET(1, D);
	EMPTY;
break;
/*SET 1, E*/
case 0xcb:
	SET(1, E);
	EMPTY;
break;
/*SET 1, H*/
case 0xcc:
	SET(1, H);
	EMPTY;
break;
/*SET 1, L*/
case 0xcd:
	SET(1, L);
	EMPTY;
break;
/*SET 1, (HL)*/
case 0xce:
	temp8=READ_BYTE(HL);
	SET(1, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 1, A*/
case 0xcf:
	SET(1, A);
	EMPTY;
break;
/*SET 2, B*/
case 0xd0:
	SET(2, B);
	EMPTY;
break;
/*SET 2, C*/
case 0xd1:
	SET(2, C);
	EMPTY;
break;
/*SET 2, D*/
case 0xd2:
	SET(2, D);
	EMPTY;
break;
/*SET 2, E*/
case 0xd3:
	SET(2, E);
	EMPTY;
break;
/*SET 2, H*/
case 0xd4:
	SET(2, H);
	EMPTY;
break;
/*SET 2, L*/
case 0xd5:
	SET(2, L);
	EMPTY;
break;
/*SET 2, (HL)*/
case 0xd6:
	temp8=READ_BYTE(HL);
	SET(2, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 2, A*/
case 0xd7:
	SET(2, A);
	EMPTY;
break;
/*SET 3, B*/
case 0xd8:
	SET(3, B);
	EMPTY;
break;
/*SET 3, C*/
case 0xd9:
	SET(3, C);
	EMPTY;
break;
/*SET 3, D*/
case 0xda:
	SET(3, D);
	EMPTY;
break;
/*SET 3, E*/
case 0xdb:
	SET(3, E);
	EMPTY;
break;
/*SET 3, H*/
case 0xdc:
	SET(3, H);
	EMPTY;
break;
/*SET 3, L*/
case 0xdd:
	SET(3, L);
	EMPTY;
break;
/*SET 3, (HL)*/
case 0xde:
	temp8=READ_BYTE(HL);
	SET(3, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 3, A*/
case 0xdf:
	SET(3, A);
	EMPTY;
break;
/*SET 4, B*/
case 0xe0:
	SET(4, B);
	EMPTY;
break;
/*SET 4, C*/
case 0xe1:
	SET(4, C);
	EMPTY;
break;
/*SET 4, D*/
case 0xe2:
	SET(4, D);
	EMPTY;
break;
/*SET 4, E*/
case 0xe3:
	SET(4, E);
	EMPTY;
break;
/*SET 4, H*/
case 0xe4:
	SET(4, H);
	EMPTY;
break;
/*SET 4, L*/
case 0xe5:
	SET(4, L);
	EMPTY;
break;
/*SET 4, (HL)*/
case 0xe6:
	temp8=READ_BYTE(HL);
	SET(4, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 4, A*/
case 0xe7:
	SET(4, A);
	EMPTY;
break;
/*SET 5, B*/
case 0xe8:
	SET(5, B);
	EMPTY;
break;
/*SET 5, C*/
case 0xe9:
	SET(5, C);
	EMPTY;
break;
/*SET 5, D*/
case 0xea:
	SET(5, D);
	EMPTY;
break;
/*SET 5, E*/
case 0xeb:
	SET(5, E);
	EMPTY;
break;
/*SET 5, H*/
case 0xec:
	SET(5, H);
	EMPTY;
break;
/*SET 5, L*/
case 0xed:
	SET(5, L);
	EMPTY;
break;
/*SET 5, (HL)*/
case 0xee:
	temp8=READ_BYTE(HL);
	SET(5, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 5, A*/
case 0xef:
	SET(5, A);
	EMPTY;
break;
/*SET 6, B*/
case 0xf0:
	SET(6, B);
	EMPTY;
break;
/*SET 6, C*/
case 0xf1:
	SET(6, C);
	EMPTY;
break;
/*SET 6, D*/
case 0xf2:
	SET(6, D);
	EMPTY;
break;
/*SET 6, E*/
case 0xf3:
	SET(6, E);
	EMPTY;
break;
/*SET 6, H*/
case 0xf4:
	SET(6, H);
	EMPTY;
break;
/*SET 6, L*/
case 0xf5:
	SET(6, L);
	EMPTY;
break;
/*SET 6, (HL)*/
case 0xf6:
	temp8=READ_BYTE(HL);
	SET(6, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 6, A*/
case 0xf7:
	SET(6, A);
	EMPTY;
break;
/*SET 7, B*/
case 0xf8:
	SET(7, B);
	EMPTY;
break;
/*SET 7, C*/
case 0xf9:
	SET(7, C);
	EMPTY;
break;
/*SET 7, D*/
case 0xfa:
	SET(7, D);
	EMPTY;
break;
/*SET 7, E*/
case 0xfb:
	SET(7, E);
	EMPTY;
break;
/*SET 7, H*/
case 0xfc:
	SET(7, H);
	EMPTY;
break;
/*SET 7, L*/
case 0xfd:
	SET(7, L);
	EMPTY;
break;
/*SET 7, (HL)*/
case 0xfe:
	temp8=READ_BYTE(HL);
	SET(7, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11-4);
break;
/*SET 7, A*/
case 0xff:
	SET(7, A);
	EMPTY;
break;
}
}
