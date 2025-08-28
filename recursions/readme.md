### 19.1 What happens if a recursive function never returns?
---
### 19.2 What is a recursive function’s base case?
---
### 19.3 What will the following program display?
```bash 
#include <iostream>
using namespace std;
// Function prototype
void showMe(int arg);
int main()
{
int num = 0;
showMe(num);
return 0;
}
void showMe(int arg)
{
if (arg < 10)
showMe(++arg);
else
cout << arg << endl;
}
```
---
### 19.4 What is the difference between direct and indirect recursion?
---