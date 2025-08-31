## Charge Account Validation
## Write a program that lets the user enter a charge account number. The program should determine if the number is valid by checking for it in the following list:
```
5658845 4520125 7895122 8777541 8451277 1302850
8080152 4562555 5552012 5050552 7825877 1250255
1005231 6545231 3852085 7576651 7881200 4581002
```
### The list of numbers above should be initialized in a single-dimensional array. A simple linear search should be used to locate the number entered by the user. If the user enters  number that is in the array, the program should display a message saying that the number is valid. If the user enters a number that is not in the array, the program should display a message indicating that the number is invalid.
---
## Lottery Winners
### A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit “lucky” combinations. Write a program that initializes an array or a vector with these numbers and then lets the player enter this week’s winning 5-digit number.
1. The program should perform a linear search through the list of the player’s numbers and report whether or not one of the tickets is a winner this week. Here are the numbers:
```
13579 26791 26792 33445 55555
62483 77777 79422 85647 93121
```
---
## String Selection Sort
### Modify the selectionSort function presented in this chapter so it sorts an array of strings instead of an array of ints. Test the function with a driver program. Use Program 8-8 as a skeleton to complete.
- Program 8-8
``` bash
#include <iostream>
#include <string>
using namespace std;
int main()
{
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };
// Insert your code to complete this program
return 0;
}
```
---