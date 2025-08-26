## Following is the list of questions: 
### 9.1 Write a statement that displays the address of the variable count.
---
### 9.2 Write the definition statement for a variable fltPtr. The variable should be a pointer to a float.
---
### 9.3 List three uses of the * symbol in C++.
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