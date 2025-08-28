/*
19.1: If a recursive function never returns then, it uses a lot of memory and becomes infinite function and the program crashes.
19.2: Base case of recursive function means a certain condition to end the program,
like in fibonacci:
when (x==0) we should return the function
like:
    int fib(int n){
        if(n==0){
            return 1;
    }
        else{
            return n * fib(n-1);
        }
    }

19.4:
direction recursion measns: we call a functoin that like in fibonacci one,
indirect recursion means: we call a recursive function and inside it there is another recursive function.
*/

/*
Output:
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

Answer: 10
*/



