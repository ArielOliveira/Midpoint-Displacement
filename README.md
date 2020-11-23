<img src="https://github.com/ArielOliveira/Midpoint-Displacement/blob/master/demo/wideCurve.png" width="270" height="270">

# Midpoint-Displacement
A recursive implementation of Midpoint Displacement algorithm

## Contents

- [About](#about)
- [Implementation](#implementation)
- [Execution](#execution)
- [Demo](#demo)

## About
- A C implementation of midpoint displacement algorithm. This algorithm takes an 1D array and fills it with values which will represent
the height of a given x, y point.

## Implementation
- The recursive implementation goes as follows:
  - 1 Take an array and set random values at the first and last value
  - 2 Take the average of the two values and set it to the middle of array
  - 3 Pass first and middle value to a function | Pass middle and last value to a function 
    - 1 if first + last / 2 <= 1 return
    - 2 take a new middle point between first and last
    - 3 set displacement to the new middle point from average of the two values 
    - 4 Repeat step 3

          
## Execution
- The executable takes 3 parameters
  - -d: A float that determines the roughness of the curve, ranges from 0.0 to 0.9. The default is 0.5
  - -r: The resolution of the image, by default it will be 1366x768
  - -o: The file name output
