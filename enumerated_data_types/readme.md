## Questions set
### 11.21 Look at the following declaration.
- enum Flower { ROSE, DAISY, PETUNIA }; 
### In memory, what value will be stored for the enumerator ROSE? For DAISY? For PETUNIA?
---
### 11.22 What will the following code display?
``` bash
enum { HOBBIT, ELF = 7, DRAGON };
cout << HOBBIT << " " << ELF << " " << DRAGON << endl;
```
---
### 11.23 Does the enumerated data type declared in Checkpoint Question 11.22 have a name, or is it anonymous?
---
### 11.24 What will the following code display?
```bash 
enum Letters { Z, Y, X };
if (Z > X)
cout << "Z is greater than X. \n";
else
cout << "Z is not greater than X. \n";
```
---
### 11.25 Will the following code cause an error, or will it compile without any errors? If it causes an error, rewrite it so it compiles.
```bash 
enum Color { RED, GREEN, BLUE };
Color c;
c = 0;
```
---

### 11.26 Will the following code cause an error, or will it compile without any errors? If it causes an error, rewrite it so it compiles.
```bash
enum Color { RED, GREEN, BLUE };
Color c = RED;
c++;
```