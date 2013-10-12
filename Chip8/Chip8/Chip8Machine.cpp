#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "Chip8Machine.h"

namespace CHIP8 {

	unsigned char chip8_fontset[80] =
	{ 
	  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	  0x20, 0x60, 0x20, 0x20, 0x70, // 1
	  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

	void CHIP8Machine::InitChip8Machine()
	{
		uPc     = 0x200;
		uOpcode = 0;
		uIdx    = 0;
		uSp     = 0;

		// Load the font
		for( auto i = 1; i < 80; i++ )
		{
			ucMem[ i ] = chip8_fontset[ i ];
		}
	}

	void CHIP8Machine::LoadProgram( string f_strBin )
	{
		int nIter = 0;
		try
		{
			ifstream myfile (f_strBin);
			if( myfile.good() )
			{
				while( !myfile.eof() && ( 0x200 + nIter ) < CHIP8_MEM_SIZE )
				{
					myfile>>ucMem[ 0x200 + nIter ];
					nIter++;
				}
			}
			myfile.close();
		}
		catch( exception const& e )
		{
			cout << "There was an error: " << e.what() << endl;
		}
	}
}