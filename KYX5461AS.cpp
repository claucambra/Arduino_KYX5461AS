/*
 * KYX-5416AS library for simplifying printing to these types of displays.
 * Created by Claudio Cambra, 2020.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */

#include "Arduino.h"
#include "KYX5461AS.h"

KYX5461AS::KYX5461AS(int boardA, int boardB, int boardC, int boardD, int boardE, int boardF, int boardG, int boardDp, int boardD1, int boardD2, int boardD3, int boardD4) {
	_pinA = boardA;
	_pinB = boardB;
	_pinC = boardC;
	_pinD = boardD;
	_pinE = boardE;
	_pinF = boardF;
	_pinG = boardG;
	_pinDp = boardDp;
	_D1 = boardD1;
	_D2 = boardD2;
	_D3 = boardD3;
	_D4 = boardD4;
	
	pinMode(_pinA, OUTPUT);     
	pinMode(_pinB, OUTPUT);     
	pinMode(_pinC, OUTPUT);     
	pinMode(_pinD, OUTPUT);     
	pinMode(_pinE, OUTPUT);     
	pinMode(_pinF, OUTPUT);     
	pinMode(_pinG, OUTPUT); 
	pinMode(_pinDp, OUTPUT);
	pinMode(_D1, OUTPUT);  
	pinMode(_D2, OUTPUT);  
	pinMode(_D3, OUTPUT);  
	pinMode(_D4, OUTPUT);
}

void KYX5461AS::reset() {
  digitalWrite(_D1, HIGH);
  digitalWrite(_D2, HIGH);
  digitalWrite(_D3, HIGH);
  digitalWrite(_D4, HIGH);
  digitalWrite(_pinA, LOW);   
  digitalWrite(_pinB, LOW);   
  digitalWrite(_pinC, LOW);   
  digitalWrite(_pinD, LOW);   
  digitalWrite(_pinE, LOW);   
  digitalWrite(_pinF, LOW);   
  digitalWrite(_pinG, LOW);
  digitalWrite(_pinDp, LOW);
}

void KYX5461AS::print(int numToPrint, int displayDigit, bool decPoint = false) {
  int D1State, D2State, D3State, D4State;
  switch(displayDigit) {
    case 1:
      D1State = LOW;
      D2State = HIGH;
      D3State = HIGH;
      D4State = HIGH;
      break;
    case 2:
      D1State = HIGH;
      D2State = LOW;
      D3State = HIGH;
      D4State = HIGH;
      break;
    case 3:
      D1State = HIGH;
      D2State = HIGH;
      D3State = LOW;
      D4State = HIGH;
      break;
    case 4:
      D1State = HIGH;
      D2State = HIGH;
      D3State = HIGH;
      D4State = LOW;
      break;
  }

  digitalWrite(_D1, D1State);
  digitalWrite(_D2, D2State);
  digitalWrite(_D3, D3State);
  digitalWrite(_D4, D4State);

  int pinAstate, pinBstate, pinCstate, pinDstate, pinEstate, pinFstate, pinGstate;
  switch(numToPrint) {
    case 0:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = HIGH;   
      pinFstate = HIGH;   
      pinGstate = LOW;
      break;
    case 1:
      pinAstate = LOW;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = LOW;   
      pinEstate = LOW;   
      pinFstate = LOW;   
      pinGstate = LOW;
      break;
    case 2:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = LOW;   
      pinDstate = HIGH;   
      pinEstate = HIGH;   
      pinFstate = LOW;   
      pinGstate = HIGH;
      break;
    case 3:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = LOW;   
      pinFstate = LOW;   
      pinGstate = HIGH;
      break;
    case 4:
      pinAstate = LOW;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = LOW;   
      pinEstate = LOW;   
      pinFstate = HIGH;   
      pinGstate = HIGH;
      break;
    case 5:
      pinAstate = HIGH;   
      pinBstate = LOW;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = LOW;   
      pinFstate = HIGH;   
      pinGstate = HIGH;
      break;
    case 6:
      pinAstate = HIGH;   
      pinBstate = LOW;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = HIGH;   
      pinFstate = HIGH;   
      pinGstate = HIGH;
      break;
    case 7:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = LOW;   
      pinEstate = LOW;   
      pinFstate = LOW;   
      pinGstate = LOW;
      break;
    case 8:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = HIGH;   
      pinFstate = HIGH;   
      pinGstate = HIGH;
      break;
    case 9:
      pinAstate = HIGH;   
      pinBstate = HIGH;   
      pinCstate = HIGH;   
      pinDstate = HIGH;   
      pinEstate = LOW;   
      pinFstate = HIGH;   
      pinGstate = HIGH;
      break;
  }

  digitalWrite(_pinA, pinAstate);   
  digitalWrite(_pinB, pinBstate);   
  digitalWrite(_pinC, pinCstate);   
  digitalWrite(_pinD, pinDstate);   
  digitalWrite(_pinE, pinEstate);   
  digitalWrite(_pinF, pinFstate);   
  digitalWrite(_pinG, pinGstate);

  if(decPoint == true) 
    digitalWrite(_pinDp, HIGH);
  else
    digitalWrite(_pinDp, LOW);
}

void KYX5461AS::printNums(int nums[], int delayBwNums = 4) {
  ::KYX5461AS::print(nums[0],1);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[1],2);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[2],3);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[3],4);
  delay(delayBwNums);
}

void KYX5461AS::printAll(int nums[], bool dpPos[], int delayBwNums = 4) {
  ::KYX5461AS::print(nums[0],1,dpPos[0]);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[1],2,dpPos[1]);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[2],3,dpPos[2]);
  delay(delayBwNums);
  ::KYX5461AS::print(nums[3],4,dpPos[3]);
  delay(delayBwNums);
}
