# Arduino_KYX5461AS
An arduino library that simplifies printing to the widely available KYX-5461AS 7-segment display.

## Setup

To enable this library you must first create a **KYX5461AS** object in your sketch.

You must provide the constructor with the correct pins.

```C++
KYX5461AS display1(2,3,4,5,6,7,8,13,9,10,11,12);
// This creates an object with name display1 
```
The order goes:
1. Segment A
2. Segment B
3. Segment C
4. Segment D
5. Segment E
6. Segment F
7. Segment G
8. Decimal Point
9. Digit 1
10. Digit 2
11. Digit 3
12. Digit 4

[Segment Diagram](https://commons.wikimedia.org/wiki/File%3A7_segment_display_labeled.svg)

![display pins](https://www.circuitbasics.com/wp-content/uploads/2017/05/Arduino-7-Segment-Tutorial-4-Digit-Display-Pin-Diagram-768x440.png)

## Use
This library provides a number of methods for KYX5461AS type objects.

Below, 'display' is used as a placeholder.

### display.reset()
Resets the display to all digits and segments being off.

### display.print(integer1, integer2, boolean)
This method handles the displaying of numbers and decimla points on the display.

It has two obligatory arguments and an optional one:
1. Argument 1 is the number you'd like to display, ranging from 0 to 9.
2. Argument 2 is the digit number on the display you'd like to print to, ranging from 1-4.
3. Argument 3 is an optional boolean which dictates whether to engage the decimal point. The default is *false*.

//Note: to avoid ghosting it is recommended that you add a delay of at least 1 millisecond to each consecutive display digit you'd like to print to.

Example:
```C++
display.print(1,1);
delay(1);
display.print(2,2,true);
delay(1);
display.print(3,3,false);
delay(1);
display.print(4,4);
delay(1);
//OUTPUT: 12.34
```

### display.printNums(integer array1, integer2)
This method simplifies printing numbers to the display by simply requiring you to provide an array of numbers to print.
This array should have numbers at indexes corresponding to their positions on the display, i.e. array[0] will print to the first display digit, array[1] to the second digit, and so on.

The second argument, an integer, is an optional one that allows you to select the delay between the displaying of each number on the display. The default is 4, as I found this to be the best setting to prevent ghosting of the display and to avoid blinking of the digits.

```C++
int numsToPrint[] = {4,3,2,1};
display.printNums{numsToPrint};
//OUTPUT: 4321
```

### display.printAll(integer array1, boolean array2, integer3)
This method works in almost the exact same way as the previous *display.printNums*, except it also allows you to select which decimal points you'd like to engage in the second argument.

```C++
int numsToPrint[] = {4,3,2,1};
bool decimalsToShow[] = {false, true, true, false};
display.printNums{numsToPrint, decimalsToShow};
//OUTPUT: 43.2.1
