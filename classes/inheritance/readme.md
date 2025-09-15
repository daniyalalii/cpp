### 15.1 Here is the first line of a class declaration. Circle the name of the base class:

class Truck : public Vehicle

### 15.2 Circle the name of the derived class in the following declaration line:

class Truck : public Vehicle

### 15.3 Suppose a program has the following class declarations:

```
class Shape
{
private:
double area;
public:
void setArea(double a)
{ area = a; }
double getArea()
{ return area; }
};
class Circle : public Shape
{
private:
double radius;
public:
void setRadius(double r)
{ radius = r;
setArea(3.14 _ r _ r); }
double getRadius()
{ return radius; }
};
```

### Answer the following questions concerning these classes:

```
A) When an object of the Circle class is created, what are its private members?
B) When an object of the Circle class is created, what are its public members?
C) What members of the Shape class are not accessible to member functions of the Circle class?
```

### 15.4 What is the difference between private members and protected members?

### 15.5 What is the difference between member access specification and class access specification?

### 15.6 Suppose a program has the following class declaration:

```
// Declaration of CheckPoint class.
class CheckPoint
{
private:
int a;
protected:
int b;
int c;
void setA(int x) { a = x;}
public:
void setB(int y) { b = y;}
void setC(int z) { c = z;}
};
```

### Answer the following questions regarding the class:

```
A) Suppose another class, Quiz, is derived from the CheckPoint class. Here is
the first line of its declaration:
class Quiz : private CheckPoint
Indicate whether each member of the CheckPoint class is private,
protected, public, or inaccessible:
a
b
c
setA
setB
setC
```

```
B) Suppose the Quiz class, derived from the CheckPoint class, is declared as
class Quiz : protected Checkpoint
Indicate whether each member of the CheckPoint class is private, protected,
public, or inaccessible:
a
b
c
setA
setB
setC
```

```
C) Suppose the Quiz class, derived from the CheckPoint class, is declared as
class Quiz : public Checkpoint
Indicate whether each member of the CheckPoint class is private, protected,
public, or inaccessible:
a
b
c
setA
setB
setC
```

```
D) Suppose the Quiz class, derived from the CheckPoint class, is declared as
class Quiz : Checkpoint
Is the CheckPoint class a private, public, or protected base class?
```

### 15.7 What will the following program display?

```
#include <iostream>
using namespace std;
class Sky
{
public:
Sky()
{ cout << "Entering the sky.\n"; }
~Sky()
{ cout << "Leaving the sky.\n"; }
};
class Ground : public Sky
{
public:
Ground()
{ cout << "Entering the Ground.\n"; }
~Ground()
{ cout << "Leaving the Ground.\n"; }
}
int main()
{
Ground object;
return 0;
}
```

### 15.8 What will the following program display?

```
#include <iostream>
using namespace std;
class Sky
{
public:
Sky()
{ cout << "Entering the sky.\n"; }
Sky(string color)
{ cout << "The sky is " << color << endl; }
~Sky()
{ cout << "Leaving the sky.\n"; }
};
class Ground : public Sky
{
public:
Ground()
{ cout << "Entering the Ground.\n"; }
Ground(string c1, string c2) : Sky(c1)
{ cout << "The ground is " << c2 << endl; }
~Ground()
{ cout << "Leaving the Ground.\n"; }
};
int main()
{
Ground object;
return 0;
```
