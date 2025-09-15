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