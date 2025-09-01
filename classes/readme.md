## 13.1 True or False: You must declare all private members of a class before the public members.
## 13.2 Assume that RetailItem is the name of a class, and the class has a void member function named setPrice, which accepts a double argument. Which of the following shows the correct use of the scope resolution operator in the member function definition?
- A) RetailItem::void setPrice(double p)
- B) void RetailItem::setPrice(double p)
## 13.3 An object’s private member variables are accessed from outside the object by
- A) public member functions
- B) any function
- C) the dot operator
- D) the scope resolution operator
## 13.4 Assume that RetailItem is the name of a class, and the class has a void member function named setPrice, which accepts a double argument. If soap is an instance of the RetailItem class, which of the following statements properly uses the soap object to call the setPrice member function?
- A) RetailItem::setPrice(1.49);
- B) soap::setPrice(1.49);
- C) soap.setPrice(1.49);
- D) soap:setPrice(1.49);
## 13.5 Complete the following code skeleton to declare a class named Date. The class should contain variables and functions to store and retrieve a date in the form 4/2/2014.
```
class Date
{
private:
public:
}
```
---
## 13.6 Why would you declare a class’s member variables private?
## 13.7 When a class’s member variables are declared private, how does code outside the class store values in, or retrieve values from, the member variables?
## 13.8 What is a class specification file? What is a class implementation file?
## 13.9 What is the purpose of an include guard?
## 13.10 Assume the following class components exist in a program:
```
BasePay class declaration
BasePay member function definitions
overtime class declaration
overtime member function definitions
In what files would you store each of these components?
```
## 13.11 What is an inline member function?
## 13.12 Briefly describe the purpose of a constructor.
## 13.13 Briefly describe the purpose of a destructor.
## 13.14 A member function that is never declared with a return data type, but that may have arguments is
```
A) The constructor
B) The destructor
C) Both the constructor and the destructor
D) Neither the constructor nor the destructor
```
## 13.15 A member function that is never declared with a return data type and can never have arguments is
```
A) The constructor
B) The destructor
C) Both the constructor and the destructor
D) Neither the constructor nor the destructor
```
## 13.16 Destructor function names always start with
```
A) A number
B) Tilde character (~)
C) A data type name
D) None of the above
```
## 13.17 A constructor that requires no arguments is called
```
A) A default constructor
B) An overloaded constructor
C) A null constructor
D) None of the above
```
## 13.18 TRUE or FALSE: Constructors are never declared with a return data type.
## 13.19 TRUE or FALSE: Destructors are never declared with a return type.
## 13.20 TRUE or FALSE: Destructors may take any number of arguments.
## 13.21 What will the following program display on the screen?
``` bash
#include <iostream>
using namespace std;
class Tank
{
private:
int gallons;
public:
Tank()
{ gallons = 50; }
Tank(int gal)
{ gallons = gal; }
int getGallons()
{ return gallons; }
};
int main()
{
Tank storage[3] = { 10, 20 };
for (int index = 0; index < 3; index++)
cout << storage[index].getGallons() << endl;
return 0;
}
```
---
## 13.22 What will the following program display on the screen?
``` bash 
#include <iostream>
using namespace std;
class Package
{
private:
int value;
public:
Package()
{ value = 7; cout << value << endl; }
Package(int v)
{ value = v; cout << value << endl; }
~Package()
{ cout << value << endl; }
};
int main()
{
Package obj1(4);
Package obj2();
Package obj3(2);
return 0;
}
```
---
## 13.23 In your answer for Checkpoint 13.22 indicate for each line of output whether the line is displayed by constructor #1, constructor #2, or the destructor.
## 13.24 Why would a member function be declared private?
## 13.25 Define an array of three InventoryItem objects.
## 13.26 Complete the following program so it defines an array of Yard objects. The program should use a loop to ask the user for the length and width of each Yard.
``` bash
#include <iostream>
using namespace std;
class Yard
{
private:
int length, width;
public:
Yard()
{ length = 0; width = 0; }
setLength(int len)
{ length = len; }
setWidth(int w)
{ width = w; }
};
int main()
{
// Finish this program
}
```
---