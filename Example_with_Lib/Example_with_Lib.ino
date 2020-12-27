#include <KYX5461AS.h>

KYX5461AS screen1(2,3,4,5,6,7,8,13,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  screen1.reset();
  int printNums[] = {1,2,3,4};
  screen1.printNums(printNums);
}
