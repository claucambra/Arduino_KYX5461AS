/*
 * KYX-5416AS library for simplifying printing to these types of displays.
 * Created by Claudio Cambra, 2020.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */

#ifndef KYX5461AS_h
#define KYX5461AS_h

#include "Arduino.h"

class KYX5461AS {
	public:
		KYX5461AS(int boardA, int boardB, int boardC, int boardD, int boardE, int boardF, int boardG, int boardDp, int boardD1, int boardD2, int boardD3, int boardD4);
		void reset();
		void print(int numToPrint, int displayDigit, bool decPoint = false);
		void printAll(int nums[], bool dpPos[] = NULL, int delayBwNums = 4);
		void printNums(int nums[], int delayBwNums = 4);
	private:
		int _pinA;
		int _pinB;
		int _pinC;
		int _pinD;
		int _pinE;
		int _pinF;
		int _pinG;
		int _pinDp;
		int _D1;
		int _D2;
		int _D3;
		int _D4;
};

#endif
