#pragma once

#define CHIP8_MEM_SIZE    4096
#define CHIP8_NUM_OF_REGS 16
#define CHIP8_DISP_WIDTH  64
#define CHIP8_DISP_HEIGHT 32
#define CHIP8_STACK_SIZE  16
#define CHIP8_KEY_SIZE    16

struct CHIP8Machine
{
    unsigned short uOpcode;
	unsigned short uIdx;
	unsigned short uPc;

	unsigned char  ucMem[ CHIP8_MEM_SIZE ];
	unsigned char  uRegs[ CHIP8_NUM_OF_REGS ];

	unsigned char  ugfx[ CHIP8_DISP_WIDTH * CHIP8_DISP_HEIGHT ];

	unsigned int   uiDelayTimer;
	unsigned int   uiSoundTimer;

	unsigned short uStack[ CHIP8_STACK_SIZE ];
	unsigned short uSp;

	unsigned char uKey[ CHIP8_KEY_SIZE ];
};