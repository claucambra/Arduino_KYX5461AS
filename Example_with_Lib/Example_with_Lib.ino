#include <KYX5461AS.h>

KYX5461AS screen1(2,3,4,5,6,7,8,13,9,10,11,12);

void setup() {
}

void loop() {
  screen1.reset();
  char stuff[] = {'H','U','C','d'};
  screen1.printNums(stuff);
}
