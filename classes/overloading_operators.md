## 14.14 Assume there is a class named Pet. Write the prototype for a member function of Pet that overloads the = operator.
## 14.15 Assume that dog and cat are instances of the Pet class, which has overloaded the = operator. Rewrite the following statement so it appears in function call notation instead of operator notation: dog = cat;
## 14.16 What is the disadvantage of an overloaded = operator returning void?
## 14.17 Describe the purpose of the this pointer.
## 14.18 The this pointer is automatically passed to what type of functions?
## 14.19 Assume there is a class named Animal that overloads the = and + operators. In the following statement, assume cat, tiger, and wildcat are all instances of the Animal class: wildcat = cat + tiger; Of the three objects, wildcat, cat, or tiger, which is calling the operator+ function? Which object is passed as an argument into the function?
## 14.20 What does the use of a dummy parameter in a unary operator function indicate to the compiler?
## 14.21 Describe the values that should be returned from functions that overload relational operators.
## 14.22 What is the advantage of overloading the << and >> operators?
## 14.23 What type of object should an overloaded << operator function return?
## 14.24 What type of object should an overloaded >> operator function return?
## 14.25 If an overloaded << or >> operator accesses a private member of a class, what must be done in that class’s declaration?
## 14.26 Assume the class NumList has overloaded the [] operator. In the expression below, list1 is an instance of the NumList class: list1[25]
- Rewrite the expression above to explicitly call the function that overloads the [] operator.
---