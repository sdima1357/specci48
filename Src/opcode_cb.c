//~ void opcode_cb(u8 bt)
{
switch (opcode) 
{
/*RLC B*/
case 0x00:
	RLC(B);
	T_WAIT_UNTIL(4);
break;
/*RLC C*/
case 0x01:
	RLC(C);
	T_WAIT_UNTIL(4);
break;
/*RLC D*/
case 0x02:
	RLC(D);
	T_WAIT_UNTIL(4);
break;
/*RLC E*/
case 0x03:
	RLC(E);
	T_WAIT_UNTIL(4);
break;
/*RLC H*/
case 0x04:
	RLC(H);
	T_WAIT_UNTIL(4);
break;
/*RLC L*/
case 0x05:
	RLC(L);
	T_WAIT_UNTIL(4);
break;
/*RLC (HL)*/
case 0x06:
	temp8=READ_BYTE(HL);
	RLC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RLC A*/
case 0x07:
	RLC(A);
	T_WAIT_UNTIL(4);
break;
/*RRC B*/
case 0x08:
	RRC(B);
	T_WAIT_UNTIL(4);
break;
/*RRC C*/
case 0x09:
	RRC(C);
	T_WAIT_UNTIL(4);
break;
/*RRC D*/
case 0x0a:
	RRC(D);
	T_WAIT_UNTIL(4);
break;
/*RRC E*/
case 0x0b:
	RRC(E);
	T_WAIT_UNTIL(4);
break;
/*RRC H*/
case 0x0c:
	RRC(H);
	T_WAIT_UNTIL(4);
break;
/*RRC L*/
case 0x0d:
	RRC(L);
	T_WAIT_UNTIL(4);
break;
/*RRC (HL)*/
case 0x0e:
	temp8=READ_BYTE(HL);
	RRC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RRC A*/
case 0x0f:
	RRC(A);
	T_WAIT_UNTIL(4);
break;
/*RL B*/
case 0x10:
	RL(B);
	T_WAIT_UNTIL(4);
break;
/*RL C*/
case 0x11:
	RL(C);
	T_WAIT_UNTIL(4);
break;
/*RL D*/
case 0x12:
	RL(D);
	T_WAIT_UNTIL(4);
break;
/*RL E*/
case 0x13:
	RL(E);
	T_WAIT_UNTIL(4);
break;
/*RL H*/
case 0x14:
	RL(H);
	T_WAIT_UNTIL(4);
break;
/*RL L*/
case 0x15:
	RL(L);
	T_WAIT_UNTIL(4);
break;
/*RL (HL)*/
case 0x16:
	temp8=READ_BYTE(HL);
	RL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RL A*/
case 0x17:
	RL(A);
	T_WAIT_UNTIL(4);
break;
/*RR B*/
case 0x18:
	RR(B);
	T_WAIT_UNTIL(4);
break;
/*RR C*/
case 0x19:
	RR(C);
	T_WAIT_UNTIL(4);
break;
/*RR D*/
case 0x1a:
	RR(D);
	T_WAIT_UNTIL(4);
break;
/*RR E*/
case 0x1b:
	RR(E);
	T_WAIT_UNTIL(4);
break;
/*RR H*/
case 0x1c:
	RR(H);
	T_WAIT_UNTIL(4);
break;
/*RR L*/
case 0x1d:
	RR(L);
	T_WAIT_UNTIL(4);
break;
/*RR (HL)*/
case 0x1e:
	temp8=READ_BYTE(HL);
	RR(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RR A*/
case 0x1f:
	RR(A);
	T_WAIT_UNTIL(4);
break;
/*SLA B*/
case 0x20:
	SLA(B);
	T_WAIT_UNTIL(4);
break;
/*SLA C*/
case 0x21:
	SLA(C);
	T_WAIT_UNTIL(4);
break;
/*SLA D*/
case 0x22:
	SLA(D);
	T_WAIT_UNTIL(4);
break;
/*SLA E*/
case 0x23:
	SLA(E);
	T_WAIT_UNTIL(4);
break;
/*SLA H*/
case 0x24:
	SLA(H);
	T_WAIT_UNTIL(4);
break;
/*SLA L*/
case 0x25:
	SLA(L);
	T_WAIT_UNTIL(4);
break;
/*SLA (HL)*/
case 0x26:
	temp8=READ_BYTE(HL);
	SLA(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SLA A*/
case 0x27:
	SLA(A);
	T_WAIT_UNTIL(4);
break;
/*SRA B*/
case 0x28:
	SRA(B);
	T_WAIT_UNTIL(4);
break;
/*SRA C*/
case 0x29:
	SRA(C);
	T_WAIT_UNTIL(4);
break;
/*SRA D*/
case 0x2a:
	SRA(D);
	T_WAIT_UNTIL(4);
break;
/*SRA E*/
case 0x2b:
	SRA(E);
	T_WAIT_UNTIL(4);
break;
/*SRA H*/
case 0x2c:
	SRA(H);
	T_WAIT_UNTIL(4);
break;
/*SRA L*/
case 0x2d:
	SRA(L);
	T_WAIT_UNTIL(4);
break;
/*SRA (HL)*/
case 0x2e:
	temp8=READ_BYTE(HL);
	SRA(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SRA A*/
case 0x2f:
	SRA(A);
	T_WAIT_UNTIL(4);
break;
/*SLL B*/
case 0x30:
	SLL(B);
	T_WAIT_UNTIL(4);
break;
/*SLL C*/
case 0x31:
	SLL(C);
	T_WAIT_UNTIL(4);
break;
/*SLL D*/
case 0x32:
	SLL(D);
	T_WAIT_UNTIL(4);
break;
/*SLL E*/
case 0x33:
	SLL(E);
	T_WAIT_UNTIL(4);
break;
/*SLL H*/
case 0x34:
	SLL(H);
	T_WAIT_UNTIL(4);
break;
/*SLL L*/
case 0x35:
	SLL(L);
	T_WAIT_UNTIL(4);
break;
/*SLL (HL)*/
case 0x36:
	temp8=READ_BYTE(HL);
	SLL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SLL A*/
case 0x37:
	SLL(A);
	T_WAIT_UNTIL(4);
break;
/*SRL B*/
case 0x38:
	SRL(B);
	T_WAIT_UNTIL(4);
break;
/*SRL C*/
case 0x39:
	SRL(C);
	T_WAIT_UNTIL(4);
break;
/*SRL D*/
case 0x3a:
	SRL(D);
	T_WAIT_UNTIL(4);
break;
/*SRL E*/
case 0x3b:
	SRL(E);
	T_WAIT_UNTIL(4);
break;
/*SRL H*/
case 0x3c:
	SRL(H);
	T_WAIT_UNTIL(4);
break;
/*SRL L*/
case 0x3d:
	SRL(L);
	T_WAIT_UNTIL(4);
break;
/*SRL (HL)*/
case 0x3e:
	temp8=READ_BYTE(HL);
	SRL(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SRL A*/
case 0x3f:
	SRL(A);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, B*/
case 0x40:
	BIT(0, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, C*/
case 0x41:
	BIT(0, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, D*/
case 0x42:
	BIT(0, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, E*/
case 0x43:
	BIT(0, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, H*/
case 0x44:
	BIT(0, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, L*/
case 0x45:
	BIT(0, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 0, (HL)*/
case 0x46:
	temp8=READ_BYTE(HL);
	BIT_MPTR(0, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 0, A*/
case 0x47:
	BIT(0, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, B*/
case 0x48:
	BIT(1, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, C*/
case 0x49:
	BIT(1, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, D*/
case 0x4a:
	BIT(1, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, E*/
case 0x4b:
	BIT(1, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, H*/
case 0x4c:
	BIT(1, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, L*/
case 0x4d:
	BIT(1, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 1, (HL)*/
case 0x4e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(1, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 1, A*/
case 0x4f:
	BIT(1, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, B*/
case 0x50:
	BIT(2, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, C*/
case 0x51:
	BIT(2, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, D*/
case 0x52:
	BIT(2, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, E*/
case 0x53:
	BIT(2, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, H*/
case 0x54:
	BIT(2, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, L*/
case 0x55:
	BIT(2, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 2, (HL)*/
case 0x56:
	temp8=READ_BYTE(HL);
	BIT_MPTR(2, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 2, A*/
case 0x57:
	BIT(2, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, B*/
case 0x58:
	BIT(3, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, C*/
case 0x59:
	BIT(3, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, D*/
case 0x5a:
	BIT(3, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, E*/
case 0x5b:
	BIT(3, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, H*/
case 0x5c:
	BIT(3, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, L*/
case 0x5d:
	BIT(3, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 3, (HL)*/
case 0x5e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(3, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 3, A*/
case 0x5f:
	BIT(3, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, B*/
case 0x60:
	BIT(4, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, C*/
case 0x61:
	BIT(4, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, D*/
case 0x62:
	BIT(4, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, E*/
case 0x63:
	BIT(4, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, H*/
case 0x64:
	BIT(4, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, L*/
case 0x65:
	BIT(4, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 4, (HL)*/
case 0x66:
	temp8=READ_BYTE(HL);
	BIT_MPTR(4, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 4, A*/
case 0x67:
	BIT(4, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, B*/
case 0x68:
	BIT(5, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, C*/
case 0x69:
	BIT(5, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, D*/
case 0x6a:
	BIT(5, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, E*/
case 0x6b:
	BIT(5, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, H*/
case 0x6c:
	BIT(5, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, L*/
case 0x6d:
	BIT(5, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 5, (HL)*/
case 0x6e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(5, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 5, A*/
case 0x6f:
	BIT(5, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, B*/
case 0x70:
	BIT(6, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, C*/
case 0x71:
	BIT(6, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, D*/
case 0x72:
	BIT(6, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, E*/
case 0x73:
	BIT(6, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, H*/
case 0x74:
	BIT(6, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, L*/
case 0x75:
	BIT(6, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 6, (HL)*/
case 0x76:
	temp8=READ_BYTE(HL);
	BIT_MPTR(6, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 6, A*/
case 0x77:
	BIT(6, A);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, B*/
case 0x78:
	BIT(7, B);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, C*/
case 0x79:
	BIT(7, C);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, D*/
case 0x7a:
	BIT(7, D);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, E*/
case 0x7b:
	BIT(7, E);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, H*/
case 0x7c:
	BIT(7, H);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, L*/
case 0x7d:
	BIT(7, L);
	T_WAIT_UNTIL(4);
break;
/*BIT 7, (HL)*/
case 0x7e:
	temp8=READ_BYTE(HL);
	BIT_MPTR(7, temp8);
	T_WAIT_UNTIL(8);
break;
/*BIT 7, A*/
case 0x7f:
	BIT(7, A);
	T_WAIT_UNTIL(4);
break;
/*RES 0, B*/
case 0x80:
	RES(0, B);
	T_WAIT_UNTIL(4);
break;
/*RES 0, C*/
case 0x81:
	RES(0, C);
	T_WAIT_UNTIL(4);
break;
/*RES 0, D*/
case 0x82:
	RES(0, D);
	T_WAIT_UNTIL(4);
break;
/*RES 0, E*/
case 0x83:
	RES(0, E);
	T_WAIT_UNTIL(4);
break;
/*RES 0, H*/
case 0x84:
	RES(0, H);
	T_WAIT_UNTIL(4);
break;
/*RES 0, L*/
case 0x85:
	RES(0, L);
	T_WAIT_UNTIL(4);
break;
/*RES 0, (HL)*/
case 0x86:
	temp8=READ_BYTE(HL);
	RES(0, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 0, A*/
case 0x87:
	RES(0, A);
	T_WAIT_UNTIL(4);
break;
/*RES 1, B*/
case 0x88:
	RES(1, B);
	T_WAIT_UNTIL(4);
break;
/*RES 1, C*/
case 0x89:
	RES(1, C);
	T_WAIT_UNTIL(4);
break;
/*RES 1, D*/
case 0x8a:
	RES(1, D);
	T_WAIT_UNTIL(4);
break;
/*RES 1, E*/
case 0x8b:
	RES(1, E);
	T_WAIT_UNTIL(4);
break;
/*RES 1, H*/
case 0x8c:
	RES(1, H);
	T_WAIT_UNTIL(4);
break;
/*RES 1, L*/
case 0x8d:
	RES(1, L);
	T_WAIT_UNTIL(4);
break;
/*RES 1, (HL)*/
case 0x8e:
	temp8=READ_BYTE(HL);
	RES(1, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 1, A*/
case 0x8f:
	RES(1, A);
	T_WAIT_UNTIL(4);
break;
/*RES 2, B*/
case 0x90:
	RES(2, B);
	T_WAIT_UNTIL(4);
break;
/*RES 2, C*/
case 0x91:
	RES(2, C);
	T_WAIT_UNTIL(4);
break;
/*RES 2, D*/
case 0x92:
	RES(2, D);
	T_WAIT_UNTIL(4);
break;
/*RES 2, E*/
case 0x93:
	RES(2, E);
	T_WAIT_UNTIL(4);
break;
/*RES 2, H*/
case 0x94:
	RES(2, H);
	T_WAIT_UNTIL(4);
break;
/*RES 2, L*/
case 0x95:
	RES(2, L);
	T_WAIT_UNTIL(4);
break;
/*RES 2, (HL)*/
case 0x96:
	temp8=READ_BYTE(HL);
	RES(2, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 2, A*/
case 0x97:
	RES(2, A);
	T_WAIT_UNTIL(4);
break;
/*RES 3, B*/
case 0x98:
	RES(3, B);
	T_WAIT_UNTIL(4);
break;
/*RES 3, C*/
case 0x99:
	RES(3, C);
	T_WAIT_UNTIL(4);
break;
/*RES 3, D*/
case 0x9a:
	RES(3, D);
	T_WAIT_UNTIL(4);
break;
/*RES 3, E*/
case 0x9b:
	RES(3, E);
	T_WAIT_UNTIL(4);
break;
/*RES 3, H*/
case 0x9c:
	RES(3, H);
	T_WAIT_UNTIL(4);
break;
/*RES 3, L*/
case 0x9d:
	RES(3, L);
	T_WAIT_UNTIL(4);
break;
/*RES 3, (HL)*/
case 0x9e:
	temp8=READ_BYTE(HL);
	RES(3, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 3, A*/
case 0x9f:
	RES(3, A);
	T_WAIT_UNTIL(4);
break;
/*RES 4, B*/
case 0xa0:
	RES(4, B);
	T_WAIT_UNTIL(4);
break;
/*RES 4, C*/
case 0xa1:
	RES(4, C);
	T_WAIT_UNTIL(4);
break;
/*RES 4, D*/
case 0xa2:
	RES(4, D);
	T_WAIT_UNTIL(4);
break;
/*RES 4, E*/
case 0xa3:
	RES(4, E);
	T_WAIT_UNTIL(4);
break;
/*RES 4, H*/
case 0xa4:
	RES(4, H);
	T_WAIT_UNTIL(4);
break;
/*RES 4, L*/
case 0xa5:
	RES(4, L);
	T_WAIT_UNTIL(4);
break;
/*RES 4, (HL)*/
case 0xa6:
	temp8=READ_BYTE(HL);
	RES(4, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 4, A*/
case 0xa7:
	RES(4, A);
	T_WAIT_UNTIL(4);
break;
/*RES 5, B*/
case 0xa8:
	RES(5, B);
	T_WAIT_UNTIL(4);
break;
/*RES 5, C*/
case 0xa9:
	RES(5, C);
	T_WAIT_UNTIL(4);
break;
/*RES 5, D*/
case 0xaa:
	RES(5, D);
	T_WAIT_UNTIL(4);
break;
/*RES 5, E*/
case 0xab:
	RES(5, E);
	T_WAIT_UNTIL(4);
break;
/*RES 5, H*/
case 0xac:
	RES(5, H);
	T_WAIT_UNTIL(4);
break;
/*RES 5, L*/
case 0xad:
	RES(5, L);
	T_WAIT_UNTIL(4);
break;
/*RES 5, (HL)*/
case 0xae:
	temp8=READ_BYTE(HL);
	RES(5, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 5, A*/
case 0xaf:
	RES(5, A);
	T_WAIT_UNTIL(4);
break;
/*RES 6, B*/
case 0xb0:
	RES(6, B);
	T_WAIT_UNTIL(4);
break;
/*RES 6, C*/
case 0xb1:
	RES(6, C);
	T_WAIT_UNTIL(4);
break;
/*RES 6, D*/
case 0xb2:
	RES(6, D);
	T_WAIT_UNTIL(4);
break;
/*RES 6, E*/
case 0xb3:
	RES(6, E);
	T_WAIT_UNTIL(4);
break;
/*RES 6, H*/
case 0xb4:
	RES(6, H);
	T_WAIT_UNTIL(4);
break;
/*RES 6, L*/
case 0xb5:
	RES(6, L);
	T_WAIT_UNTIL(4);
break;
/*RES 6, (HL)*/
case 0xb6:
	temp8=READ_BYTE(HL);
	RES(6, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 6, A*/
case 0xb7:
	RES(6, A);
	T_WAIT_UNTIL(4);
break;
/*RES 7, B*/
case 0xb8:
	RES(7, B);
	T_WAIT_UNTIL(4);
break;
/*RES 7, C*/
case 0xb9:
	RES(7, C);
	T_WAIT_UNTIL(4);
break;
/*RES 7, D*/
case 0xba:
	RES(7, D);
	T_WAIT_UNTIL(4);
break;
/*RES 7, E*/
case 0xbb:
	RES(7, E);
	T_WAIT_UNTIL(4);
break;
/*RES 7, H*/
case 0xbc:
	RES(7, H);
	T_WAIT_UNTIL(4);
break;
/*RES 7, L*/
case 0xbd:
	RES(7, L);
	T_WAIT_UNTIL(4);
break;
/*RES 7, (HL)*/
case 0xbe:
	temp8=READ_BYTE(HL);
	RES(7, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*RES 7, A*/
case 0xbf:
	RES(7, A);
	T_WAIT_UNTIL(4);
break;
/*SET 0, B*/
case 0xc0:
	SET(0, B);
	T_WAIT_UNTIL(4);
break;
/*SET 0, C*/
case 0xc1:
	SET(0, C);
	T_WAIT_UNTIL(4);
break;
/*SET 0, D*/
case 0xc2:
	SET(0, D);
	T_WAIT_UNTIL(4);
break;
/*SET 0, E*/
case 0xc3:
	SET(0, E);
	T_WAIT_UNTIL(4);
break;
/*SET 0, H*/
case 0xc4:
	SET(0, H);
	T_WAIT_UNTIL(4);
break;
/*SET 0, L*/
case 0xc5:
	SET(0, L);
	T_WAIT_UNTIL(4);
break;
/*SET 0, (HL)*/
case 0xc6:
	temp8=READ_BYTE(HL);
	SET(0, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 0, A*/
case 0xc7:
	SET(0, A);
	T_WAIT_UNTIL(4);
break;
/*SET 1, B*/
case 0xc8:
	SET(1, B);
	T_WAIT_UNTIL(4);
break;
/*SET 1, C*/
case 0xc9:
	SET(1, C);
	T_WAIT_UNTIL(4);
break;
/*SET 1, D*/
case 0xca:
	SET(1, D);
	T_WAIT_UNTIL(4);
break;
/*SET 1, E*/
case 0xcb:
	SET(1, E);
	T_WAIT_UNTIL(4);
break;
/*SET 1, H*/
case 0xcc:
	SET(1, H);
	T_WAIT_UNTIL(4);
break;
/*SET 1, L*/
case 0xcd:
	SET(1, L);
	T_WAIT_UNTIL(4);
break;
/*SET 1, (HL)*/
case 0xce:
	temp8=READ_BYTE(HL);
	SET(1, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 1, A*/
case 0xcf:
	SET(1, A);
	T_WAIT_UNTIL(4);
break;
/*SET 2, B*/
case 0xd0:
	SET(2, B);
	T_WAIT_UNTIL(4);
break;
/*SET 2, C*/
case 0xd1:
	SET(2, C);
	T_WAIT_UNTIL(4);
break;
/*SET 2, D*/
case 0xd2:
	SET(2, D);
	T_WAIT_UNTIL(4);
break;
/*SET 2, E*/
case 0xd3:
	SET(2, E);
	T_WAIT_UNTIL(4);
break;
/*SET 2, H*/
case 0xd4:
	SET(2, H);
	T_WAIT_UNTIL(4);
break;
/*SET 2, L*/
case 0xd5:
	SET(2, L);
	T_WAIT_UNTIL(4);
break;
/*SET 2, (HL)*/
case 0xd6:
	temp8=READ_BYTE(HL);
	SET(2, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 2, A*/
case 0xd7:
	SET(2, A);
	T_WAIT_UNTIL(4);
break;
/*SET 3, B*/
case 0xd8:
	SET(3, B);
	T_WAIT_UNTIL(4);
break;
/*SET 3, C*/
case 0xd9:
	SET(3, C);
	T_WAIT_UNTIL(4);
break;
/*SET 3, D*/
case 0xda:
	SET(3, D);
	T_WAIT_UNTIL(4);
break;
/*SET 3, E*/
case 0xdb:
	SET(3, E);
	T_WAIT_UNTIL(4);
break;
/*SET 3, H*/
case 0xdc:
	SET(3, H);
	T_WAIT_UNTIL(4);
break;
/*SET 3, L*/
case 0xdd:
	SET(3, L);
	T_WAIT_UNTIL(4);
break;
/*SET 3, (HL)*/
case 0xde:
	temp8=READ_BYTE(HL);
	SET(3, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 3, A*/
case 0xdf:
	SET(3, A);
	T_WAIT_UNTIL(4);
break;
/*SET 4, B*/
case 0xe0:
	SET(4, B);
	T_WAIT_UNTIL(4);
break;
/*SET 4, C*/
case 0xe1:
	SET(4, C);
	T_WAIT_UNTIL(4);
break;
/*SET 4, D*/
case 0xe2:
	SET(4, D);
	T_WAIT_UNTIL(4);
break;
/*SET 4, E*/
case 0xe3:
	SET(4, E);
	T_WAIT_UNTIL(4);
break;
/*SET 4, H*/
case 0xe4:
	SET(4, H);
	T_WAIT_UNTIL(4);
break;
/*SET 4, L*/
case 0xe5:
	SET(4, L);
	T_WAIT_UNTIL(4);
break;
/*SET 4, (HL)*/
case 0xe6:
	temp8=READ_BYTE(HL);
	SET(4, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 4, A*/
case 0xe7:
	SET(4, A);
	T_WAIT_UNTIL(4);
break;
/*SET 5, B*/
case 0xe8:
	SET(5, B);
	T_WAIT_UNTIL(4);
break;
/*SET 5, C*/
case 0xe9:
	SET(5, C);
	T_WAIT_UNTIL(4);
break;
/*SET 5, D*/
case 0xea:
	SET(5, D);
	T_WAIT_UNTIL(4);
break;
/*SET 5, E*/
case 0xeb:
	SET(5, E);
	T_WAIT_UNTIL(4);
break;
/*SET 5, H*/
case 0xec:
	SET(5, H);
	T_WAIT_UNTIL(4);
break;
/*SET 5, L*/
case 0xed:
	SET(5, L);
	T_WAIT_UNTIL(4);
break;
/*SET 5, (HL)*/
case 0xee:
	temp8=READ_BYTE(HL);
	SET(5, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 5, A*/
case 0xef:
	SET(5, A);
	T_WAIT_UNTIL(4);
break;
/*SET 6, B*/
case 0xf0:
	SET(6, B);
	T_WAIT_UNTIL(4);
break;
/*SET 6, C*/
case 0xf1:
	SET(6, C);
	T_WAIT_UNTIL(4);
break;
/*SET 6, D*/
case 0xf2:
	SET(6, D);
	T_WAIT_UNTIL(4);
break;
/*SET 6, E*/
case 0xf3:
	SET(6, E);
	T_WAIT_UNTIL(4);
break;
/*SET 6, H*/
case 0xf4:
	SET(6, H);
	T_WAIT_UNTIL(4);
break;
/*SET 6, L*/
case 0xf5:
	SET(6, L);
	T_WAIT_UNTIL(4);
break;
/*SET 6, (HL)*/
case 0xf6:
	temp8=READ_BYTE(HL);
	SET(6, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 6, A*/
case 0xf7:
	SET(6, A);
	T_WAIT_UNTIL(4);
break;
/*SET 7, B*/
case 0xf8:
	SET(7, B);
	T_WAIT_UNTIL(4);
break;
/*SET 7, C*/
case 0xf9:
	SET(7, C);
	T_WAIT_UNTIL(4);
break;
/*SET 7, D*/
case 0xfa:
	SET(7, D);
	T_WAIT_UNTIL(4);
break;
/*SET 7, E*/
case 0xfb:
	SET(7, E);
	T_WAIT_UNTIL(4);
break;
/*SET 7, H*/
case 0xfc:
	SET(7, H);
	T_WAIT_UNTIL(4);
break;
/*SET 7, L*/
case 0xfd:
	SET(7, L);
	T_WAIT_UNTIL(4);
break;
/*SET 7, (HL)*/
case 0xfe:
	temp8=READ_BYTE(HL);
	SET(7, temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
break;
/*SET 7, A*/
case 0xff:
	SET(7, A);
	T_WAIT_UNTIL(4);
break;
}
}
/*
static void (*opcode_cb[0x100])(void)={
	op_CB_0x00, op_CB_0x01, op_CB_0x02, op_CB_0x03, op_CB_0x04, op_CB_0x05, op_CB_0x06, op_CB_0x07, op_CB_0x08, op_CB_0x09, op_CB_0x0a, op_CB_0x0b, op_CB_0x0c, op_CB_0x0d, op_CB_0x0e, op_CB_0x0f,
	op_CB_0x10, op_CB_0x11, op_CB_0x12, op_CB_0x13, op_CB_0x14, op_CB_0x15, op_CB_0x16, op_CB_0x17, op_CB_0x18, op_CB_0x19, op_CB_0x1a, op_CB_0x1b, op_CB_0x1c, op_CB_0x1d, op_CB_0x1e, op_CB_0x1f,
	op_CB_0x20, op_CB_0x21, op_CB_0x22, op_CB_0x23, op_CB_0x24, op_CB_0x25, op_CB_0x26, op_CB_0x27, op_CB_0x28, op_CB_0x29, op_CB_0x2a, op_CB_0x2b, op_CB_0x2c, op_CB_0x2d, op_CB_0x2e, op_CB_0x2f,
	op_CB_0x30, op_CB_0x31, op_CB_0x32, op_CB_0x33, op_CB_0x34, op_CB_0x35, op_CB_0x36, op_CB_0x37, op_CB_0x38, op_CB_0x39, op_CB_0x3a, op_CB_0x3b, op_CB_0x3c, op_CB_0x3d, op_CB_0x3e, op_CB_0x3f,
	op_CB_0x40, op_CB_0x41, op_CB_0x42, op_CB_0x43, op_CB_0x44, op_CB_0x45, op_CB_0x46, op_CB_0x47, op_CB_0x48, op_CB_0x49, op_CB_0x4a, op_CB_0x4b, op_CB_0x4c, op_CB_0x4d, op_CB_0x4e, op_CB_0x4f,
	op_CB_0x50, op_CB_0x51, op_CB_0x52, op_CB_0x53, op_CB_0x54, op_CB_0x55, op_CB_0x56, op_CB_0x57, op_CB_0x58, op_CB_0x59, op_CB_0x5a, op_CB_0x5b, op_CB_0x5c, op_CB_0x5d, op_CB_0x5e, op_CB_0x5f,
	op_CB_0x60, op_CB_0x61, op_CB_0x62, op_CB_0x63, op_CB_0x64, op_CB_0x65, op_CB_0x66, op_CB_0x67, op_CB_0x68, op_CB_0x69, op_CB_0x6a, op_CB_0x6b, op_CB_0x6c, op_CB_0x6d, op_CB_0x6e, op_CB_0x6f,
	op_CB_0x70, op_CB_0x71, op_CB_0x72, op_CB_0x73, op_CB_0x74, op_CB_0x75, op_CB_0x76, op_CB_0x77, op_CB_0x78, op_CB_0x79, op_CB_0x7a, op_CB_0x7b, op_CB_0x7c, op_CB_0x7d, op_CB_0x7e, op_CB_0x7f,
	op_CB_0x80, op_CB_0x81, op_CB_0x82, op_CB_0x83, op_CB_0x84, op_CB_0x85, op_CB_0x86, op_CB_0x87, op_CB_0x88, op_CB_0x89, op_CB_0x8a, op_CB_0x8b, op_CB_0x8c, op_CB_0x8d, op_CB_0x8e, op_CB_0x8f,
	op_CB_0x90, op_CB_0x91, op_CB_0x92, op_CB_0x93, op_CB_0x94, op_CB_0x95, op_CB_0x96, op_CB_0x97, op_CB_0x98, op_CB_0x99, op_CB_0x9a, op_CB_0x9b, op_CB_0x9c, op_CB_0x9d, op_CB_0x9e, op_CB_0x9f,
	op_CB_0xa0, op_CB_0xa1, op_CB_0xa2, op_CB_0xa3, op_CB_0xa4, op_CB_0xa5, op_CB_0xa6, op_CB_0xa7, op_CB_0xa8, op_CB_0xa9, op_CB_0xaa, op_CB_0xab, op_CB_0xac, op_CB_0xad, op_CB_0xae, op_CB_0xaf,
	op_CB_0xb0, op_CB_0xb1, op_CB_0xb2, op_CB_0xb3, op_CB_0xb4, op_CB_0xb5, op_CB_0xb6, op_CB_0xb7, op_CB_0xb8, op_CB_0xb9, op_CB_0xba, op_CB_0xbb, op_CB_0xbc, op_CB_0xbd, op_CB_0xbe, op_CB_0xbf,
	op_CB_0xc0, op_CB_0xc1, op_CB_0xc2, op_CB_0xc3, op_CB_0xc4, op_CB_0xc5, op_CB_0xc6, op_CB_0xc7, op_CB_0xc8, op_CB_0xc9, op_CB_0xca, op_CB_0xcb, op_CB_0xcc, op_CB_0xcd, op_CB_0xce, op_CB_0xcf,
	op_CB_0xd0, op_CB_0xd1, op_CB_0xd2, op_CB_0xd3, op_CB_0xd4, op_CB_0xd5, op_CB_0xd6, op_CB_0xd7, op_CB_0xd8, op_CB_0xd9, op_CB_0xda, op_CB_0xdb, op_CB_0xdc, op_CB_0xdd, op_CB_0xde, op_CB_0xdf,
	op_CB_0xe0, op_CB_0xe1, op_CB_0xe2, op_CB_0xe3, op_CB_0xe4, op_CB_0xe5, op_CB_0xe6, op_CB_0xe7, op_CB_0xe8, op_CB_0xe9, op_CB_0xea, op_CB_0xeb, op_CB_0xec, op_CB_0xed, op_CB_0xee, op_CB_0xef,
	op_CB_0xf0, op_CB_0xf1, op_CB_0xf2, op_CB_0xf3, op_CB_0xf4, op_CB_0xf5, op_CB_0xf6, op_CB_0xf7, op_CB_0xf8, op_CB_0xf9, op_CB_0xfa, op_CB_0xfb, op_CB_0xfc, op_CB_0xfd, op_CB_0xfe, op_CB_0xff
};
*/