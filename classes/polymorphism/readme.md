### 15.9 Explain the difference between overloading a function and redefining a function.

### 15.10 Explain the difference between static binding and dynamic binding.

### 15.11 Are virtual functions statically bound or dynamically bound?

### 15.12 What will the following program display?

```
#include <iostream.>
using namespace std;
class First
{
protected:
    int a;

public:
    First(int x = 1)
    {
        a = x;
    }
    int getVal()
    {
        return a;
    }
};
class Second : public First
{
private:
    int b;

public:
    Second(int y = 5)
    {
        b = y;
    }
    int getVal()
    {
        return b;
    }
};
int main()
{
    First object1;
    Second object2;
    cout << object1.getVal() << endl;
    cout << object2.getVal() << endl;
    return 0;
}
```

### 15.13 What will the following program display?

```
#include <iostream>
using namespace std;
class First
{
protected:
int a;
public:
First(int x = 1)
{ a = x; }
void twist()
{ a *= 2; }
int getVal()
{ twist(); return a; }
};
class Second : public First
{
private:
int b;
public:
Second(int y = 5)
{ b = y; }
void twist()
{ b *= 10; }
};
int main()
{
First object1;
Second object2;
cout << object1.getVal() << endl;
cout << object2.getVal() << endl;
return 0;
}
```

### 15.14 What will the following program display?

```
#include <iostream>
using namespace std;
class First
{
protected:
int a;
public:
First(int x = 1)
{ a = x; }
virtual void twist()
{ a *= 2; }
int getVal()
{ twist(); return a; }
};
class Second : public First
{
private:
int b;
public:
Second(int y = 5)
{ b = y; }
virtual void twist()
{ b *= 10; }
};
int main()
{
First object1;
Second object2;
cout << object1.getVal() << endl;
cout << object2.getVal() << endl;
return 0;
}
```

### 15.15 What will the following program display?

```
#include <iostream>
using namespace std;
class Base
{
protected:
int baseVar;
public:
Base(int val = 2)
{ baseVar = val; }
int getVar()
{ return baseVar; }
};
class Derived : public Base
{
private:
int derivedVar;
public:
Derived(int val = 100)
{ derivedVar = val; }
int getVar()
{ return derivedVar; }
};
int main()
{
Base *optr = nullptr;
Derived object;
optr = &object;
cout << optr->getVar() << endl;
return 0;
}
```
