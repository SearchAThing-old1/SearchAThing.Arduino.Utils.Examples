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
// EXAMPLE	: ex07-ramdata.ino
//===========================================================================
// Setup()
//   - Do some manipulation of memory data using RamData object.
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
#include <SearchAThing.Arduino.Utils\RamData.h>
#include <MemoryFree\MemoryFree.h>
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
	auto freeblk = FreeMemoryMaxBlock();
	auto freesum = FreeMemorySum();

	// assignment operator
	{
		auto b = RamData();
		{
			auto a = RamData(size);
			for (int i = 0; i < a.Size(); ++i) a.Buf()[i] = i;

			// if `b' contains something it will deallocated
			// and a new allocation in `b' will hold copy of `a' data
			b = a;
		} // here a destroyed, while b still live

		  // size of `b' must be the same as it was for `a'
		if (b.Size() != size) DPrintln(F("* unexpected size"));

		// content of `b' must be the same as it was for `a'
		for (int i = 0; i < b.Size(); ++i)
		{
			if (b.Buf()[i] != i) DPrintln(F("* unexpected data"));
		}
	}

	// string usage
	{
		auto a = RamData(F("   some"));
		a = a.Append(F("___text   "));
		a = a.Trim();

		if (a.StartsWith(F("some")))
		{
			DPrint('\"');
			DPrint(a);
			DPrint(F("\" starts with \"some\""));

			DPrint(F(" stripped which results in \""));
			a.StripBegin(F("some")).PrintAsChars();
			DPrintln('\"');
		}

		auto parts = a.Split('_');
		DPrint(F("words: "));
		for (int i = 0; i < parts.Size(); ++i)
		{
			DPrint('['); parts.Get(i).PrintAsChars(); DPrint(F("] "));
		}
		DPrintln();
	}

	// variable initializer
	{
		auto N = 4;
		auto a = RamData::FromArray(N, 1, 2, 3, 4);
		auto b = RamData::FromArray(N, 5, 6, 7, 8);

		DPrintln(F("some calc:"));
		for (int i = 0; i < N; ++i)
		{
			DPrint(a.Buf()[i]); DPrint(F(" + ")); DPrint(b.Buf()[i]);
			DPrint(F(" = ")); DPrintln(a.Buf()[i] + b.Buf()[i]);
		}
	}

	// memory must return to its original state
	if (FreeMemoryMaxBlock() != freeblk || FreeMemorySum() != freesum)
		DPrintln(F("* memory leak detected!"));
}

//---------------------------------------------------------------------------
// Loop
//---------------------------------------------------------------------------
void loop()
{

}
