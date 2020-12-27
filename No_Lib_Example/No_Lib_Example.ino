/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}

void KYX5461AS_reset() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}

void KYX5461AS_print(int numToPrint, int displayDigit) {
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

  digitalWrite(D1, D1State);
  digitalWrite(D2, D2State);
  digitalWrite(D3, D3State);
  digitalWrite(D4, D4State);

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

  digitalWrite(pinA, pinAstate);   
  digitalWrite(pinB, pinBstate);   
  digitalWrite(pinC, pinCstate);   
  digitalWrite(pinD, pinDstate);   
  digitalWrite(pinE, pinEstate);   
  digitalWrite(pinF, pinFstate);   
  digitalWrite(pinG, pinGstate);

}

void KYX5461AS_printAll(int nums[], int delayBwNums = 4) {
  KYX5461AS_print(nums[0],1);
  delay(delayBwNums);
  KYX5461AS_print(nums[1],2);
  delay(delayBwNums);
  KYX5461AS_print(nums[2],3);
  delay(delayBwNums);
  KYX5461AS_print(nums[3],4);
  delay(delayBwNums);
}

// the loop routine runs over and over again forever:
void loop() {
  int printNums[] = {1,2,3,4};
  KYX5461AS_printAll(printNums);
}
