/*
* The MIT License(MIT)
* Copyright(c) 2016 Lorenzo Delana, https://searchathing.com
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/

//===========================================================================
// EXAMPLE	: ex03-freememory.ino
//===========================================================================
// Setup()
//   - Print summary of free memory (max contiguous allocable block and sum
//     of all fragmented available memory).
//   - Print detailed memory layout.
// Loop()
//---------------------------------------------------------------------------
// Suggested defines for this example
//---------------------------------------------------------------------------
// SEARCHATHING_DISABLE;DPRINT_SERIAL;SERIAL_SPEED=9600
//

// SearchAThing.Arduino debug macro definitions
#include <SearchAThing.Arduino.Utils\DebugMacros.h>

//---------------------------------------------------------------------------
// Libraries
//---------------------------------------------------------------------------
#include <SearchAThing.Arduino.Utils\Util.h>
#include <MemoryFree\MemoryFree.h> // needed for FreeMemorySum()
using namespace SearchAThing::Arduino;

//---------------------------------------------------------------------------
// Setup
//---------------------------------------------------------------------------
void setup()
{
	auto a = (byte *)malloc(10);
	auto b = (byte *)malloc(20);
	auto c = (byte *)malloc(30);
	auto d = (byte *)malloc(40);
	free(a);
	free(c);

	PrintFreeMemory();

	PrintRAMLayout();

	DPrint("a="); DPrintHexln((size_t)a);
	DPrint("b="); DPrintHexln((size_t)b);
	DPrint("c="); DPrintHexln((size_t)c);
	DPrint("d="); DPrintHexln((size_t)d);
}

//---------------------------------------------------------------------------
// Loop
//---------------------------------------------------------------------------
void loop()
{

}
