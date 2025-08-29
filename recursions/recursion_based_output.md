## What are the output of following code?

```bash
#include <iostream>
using namespace std;
int function(int);
int main()
{
    int x = 10;
    cout << function(x) << endl;
    return 0;
}
int function(int num)
{
    if (num <= 0)
        return 0;
    else
        return function(num − 1) + num;
}
```

---

```bash
#include <iostream>
using namespace std;
void function(int);
int main()
{
    int x = 10;
    function(x);
    return 0;
}
void function(int num)
{
    if (num > 0)
    {
        for (int x = 0; x < num; x++)
            cout << '*';
        cout << endl;
        function(num − 1);
    }
}
```

---

``` bash
#include <iostream>
#include <string>
using namespace std;
void function(string, int, int);
int main()
{
    string mystr = "Hello";
    cout << mystr << endl;
    function(mystr, 0, mystr.size());
    return 0;
}
void function(string str, int pos, int size)
{
    if (pos < size)
    {
        function(str, pos + 1, size);
        cout << str[pos];
    }
}
```
---