#include <KYX5461AS.h>

KYX5461AS screen1(2,3,4,5,6,7,8,13,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  screen1.reset();
  char printNums[] = {'8','0','0','8'};
  screen1.printInt(3);
}
