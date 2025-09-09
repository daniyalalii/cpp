## Employee Class
Write a class named Employee that has the following member variables:
```
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee
works.
• position. A string that holds the employee’s job title.
```
### The class should have the following constructors:
```
• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee’s name, employee’s ID number, department, and position.
• A constructor that accepts the following values as arguments and assigns them to the
appropriate member variables: employee’s name and ID number. The department and position fields should be assigned an empty string ("").
• A default constructor that assigns empty strings ("") to the name, department, and position member variables, and 0 to the idNumber member variable.
```
### Write appropriate mutator functions that store values in these member variables and accessor functions that return the values in these member variables. Once you have written the class, write a separate program that creates three Employee objects to hold the following data.
```
Name            ID Number      Department      Position
Susan Meyers    47899          Accounting Vice President
Mark Jones      39119          IT              Programmer
Joy Rogers      81774          Manufacturing   Engineer
```
### The program should store this data in the three objects and then display the data for each employee on the screen.
---
## Car Class
### Write a class named Car that has the following member variables:
```
• yearModel. An int that holds the car’s year model.
• make. A string that holds the make of the car.
• speed. An int that holds the car’s current speed.
```
### In addition, the class should have the following constructor and other member functions.
```
• Constructor. The constructor should accept the car’s year model and make as arguments. These values should be assigned to the object’s yearModel and make member
variables. The constructor should also assign 0 to the speed member variables.
• Accessor. Appropriate accessor functions to get the values stored in an object’s
yearModel, make, and speed member variables.
• accelerate. The accelerate function should add 5 to the speed member variable
each time it is called.
• brake. The brake function should subtract 5 from the speed member variable each
time it is called.
```
### Demonstrate the class in a program that creates a Car object, and then calls the accelerate function five times. After each call to the accelerate function, get the current speed of the car and display it. Then, call the brake function five times.
### After each call to the brake function, get the current speed of the car and display it.
---
## RetailItem Class
### Write a class named RetailItem that holds data about an item in a retail store. The class should have the following member variables:
```
• description. A string that holds a brief description of the item.
• unitsOnHand. An int that holds the number of units currently in inventory.
• price. A double that holds the item’s retail price.
```
### Write a constructor that accepts arguments for each member variable, appropriate mutator functions that store values in these member variables, and accessor functions that return the values in these member variables. Once you have written the class, write a separate program that creates three RetailItem objects and stores the following data in them.
```
                Description         Units On Hand       Price
Item #1         Jacket              12                  59.95
Item #2         Designer Jeans      40                  34.95
Item #3         Shirt               20                  24.95
```
---
## Number Array Class
### Design a class that has an array of floating-point numbers. The constructor should accept an integer argument and dynamically allocate the array to hold that many numbers. The destructor should free the memory held by the array. In addition, there should be member functions to perform the following operations:
```
• Store a number in any element of the array
• Retrieve a number from any element of the array
• Return the highest value stored in the array
• Return the lowest value stored in the array
• Return the average of all the numbers stored in the array
```
### Demonstrate the class in a program
---
## A Game of 21
### For this assignment, you will write a program that lets the user play against the computer in a variation of the popular blackjack card game. In this variation of the game, two six-sided dice are used instead of cards. The dice are rolled, and the player tries to beat the computer’s hidden total without going over 21.
Here are some suggestions for the game’s design:
```
• Each round of the game is performed as an iteration of a loop that repeats as long
as the player agrees to roll the dice, and the player’s total does not exceed 21.
• At the beginning of each round, the program will ask the users whether they want
to roll the dice to accumulate points.
• During each round, the program simulates the rolling of two six-sided dice. It rolls
the dice first for the computer, and then it asks the user if he or she wants to roll.
• The loop keeps a running total of both the computer and the user’s points.
• The computer’s total should remain hidden until the loop has finished.
• After the loop has finished, the computer’s total is revealed, and the player with the
most points without going over 21 wins.
```
---

## Numbers Class
### Design a class Numbers that can be used to translate whole dollar amounts in the range 0 through 9999 into an English description of the number. For example, the number 713 would be translated into the string seven hundred thirteen, and 8203 would be translated into eight thousand two hundred three. The class should have a single integer member variable:
```
int number;
```
### and a static array of string objects that specify how to translate key dollar amounts into the desired format. For example, you might use static strings such as
```
string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
string hundred = "hundred";
string thousand = "thousand";
```
### The class should have a constructor that accepts a nonnegative integer and uses it to initialize the Numbers object. It should have a member function print() that prints the English description of the Numbers object. Demonstrate the class by writing a main program that asks the user to enter a number in the proper range and then prints out its English description.