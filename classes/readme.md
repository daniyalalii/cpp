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