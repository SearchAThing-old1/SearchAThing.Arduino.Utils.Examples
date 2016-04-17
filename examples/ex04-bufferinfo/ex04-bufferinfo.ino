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
// EXAMPLE	: ex04-bufferinfo.ino
//===========================================================================
// Setup()
//   - Allocate dynamic memory.
//   - Create a dyn memory tracker using BufferInfo.
//   - Do some stuff with SetLength()
//   - Release memory.
// Loop()
//---------------------------------------------------------------------------
// Suggested defines for this example
//---------------------------------------------------------------------------
// SEARCHATHING_DISABLE;DPRINT_SERIAL;SERIAL_SPEED=9600;DEBUG;DEBUG_ASSERT
//

// SearchAThing.Arduino debug macro definitions
#include <SearchAThing.Arduino.Utils\DebugMacros.h>

//---------------------------------------------------------------------------
// Libraries
//---------------------------------------------------------------------------
#include <SearchAThing.Arduino.Utils\Util.h>
#include <SearchAThing.Arduino.Utils\BufferInfo.h>
using namespace SearchAThing::Arduino;

//---------------------------------------------------------------------------
// Global
//---------------------------------------------------------------------------
const int size = 10;

//---------------------------------------------------------------------------
// Setup
//---------------------------------------------------------------------------
void setup()
{
	auto a = (byte *)malloc(size);
	auto nfo = BufferInfo(a, size);

	DPrint("a="); DPrintHex((size_t)a);
	DPrint(" length="); DPrint(nfo.Length());
	DPrint(" capacity="); DPrintln(nfo.Capacity());

	{
		auto newlen = nfo.Capacity() - 1;
		DPrint(F("- set length to ")); DPrintln(newlen);
		nfo.SetLength(newlen);
		DPrint("length="); DPrintln(nfo.Length());
	}

	{
		auto newlen = nfo.Capacity() + 1;
		DPrint(F("- set length to ")); DPrintln(newlen);
		nfo.SetLength(newlen);
		DPrint("length="); DPrintln(nfo.Length());
	}

	free(a);
}

//---------------------------------------------------------------------------
// Loop
//---------------------------------------------------------------------------
void loop()
{

}
