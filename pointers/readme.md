## Following is the list of questions:

### 9.1 Write a statement that displays the address of the variable count.

---

### 9.2 Write the definition statement for a variable fltPtr. The variable should be a pointer to a float.

---

### 9.3 List three uses of the \* symbol in C++.

---

### 9.4 What is the output of the following code?

```
int x = 50, y = 60, z = 70;
int *ptr = nullptr;
cout << x << " " << y << " " << z << endl;
ptr = &x;
*ptr *= 10;
ptr = &y;
*ptr *= 5;
ptr = &z;
*ptr *= 2;
cout << x << " " << y << " " << z << endl;
```

---

### 9.5 Rewrite the following loop so it uses pointer notation (with the indirection operator) instead of subscript notation.

```
for (int x = 0; x < 100; x++)
cout << arr[x] << endl;
```

---

### 9.6 Assume ptr is a pointer to an int and holds the address 12000. On a system with 4-byte integers, what address will be in ptr after the following statement?

```
ptr += 10;
```

---

### 9.7 Assume pint is a pointer variable. Is each of the following statements valid or invalid? If any is invalid, why?

```
A) pint++;
B) −−pint;
C) pint /= 2;
D) pint *= 4;
E) pint += x; // Assume x is an int.
```

---

### 9.8 Is each of the following definitions valid or invalid? If any is invalid, why?

```
A) int ivar;
int *iptr = &ivar;
B) int ivar, *iptr = &ivar;
C) float fvar;
int *iptr = &fvar;
D) int nums[50], *iptr = nums;
E) int *iptr = &ivar;
int ivar;
```

---

### 9.9 Assuming arr is an array of ints, will each of the following program segments display “True” or “False”?

``` bash
A) if (arr < &arr[1])
cout << "True";
else
cout << "False";
B) if (&arr[4] < &arr[1])
cout << "True";
else
cout << "False";
C) if (arr != &arr[2])
cout << "True";
else
cout << "False";
D) if (arr != &arr[0])
cout << "True";
else
cout << "False";
```
---

### 9.10 Give an example of the proper way to call the following function:

```bash
void makeNegative(int *val)
{
if (*val > 0)
*val = −(*val);
}
```
---
### 9.11 Complete the following program skeleton. When finished, the program will ask the user for a length (in inches), convert that value to centimeters, and display the result. You are to write the function convert. (Note: 1 inch = 2.54 cm. Do not modify function main.)
``` bash
#include <iostream>
#include <iomanip>
using namespace std;
// Write your function prototype here.
int main()
{
double measurement;
cout << "Enter a length in inches, and I will convert\n";
cout << "it to centimeters: ";
cin >> measurement;
convert(&measurement);
cout << fixed << setprecision(4);
cout << "Value in centimeters: " << measurement << endl;
return 0;
}
//
// Write the function convert here.
//
```
---
### 9.12 Look at the following array definition:
```
const int numbers[SIZE] = { 18, 17, 12, 14 };
```
- Suppose we want to pass the array to the function processArray in the following manner:
```
processArray(numbers, SIZE);
```
- Which of the following function headers is the correct one for the processArray function?
```
A) void processArray(const int *arr, int size)
B) void processArray(int * const arr, int size)
```
---
### 9.13 Assume ip is a pointer to an int. Write a statement that will dynamically allocate an integer variable and store its address in ip. Write a statement that will free the memory allocated in the statement you wrote above.
---
### 9.14 Assume ip is a pointer to an int. Then, write a statement that will dynamically allocate an array of 500 integers and store its address in ip. Write a statement that will free the memory allocated in the statement you just wrote.
---
### 9.15 What is a null pointer?
---
### 9.16 Give an example of a function that correctly returns a pointer.
---
### 9.17 Give an example of a function that incorrectly returns a pointer.