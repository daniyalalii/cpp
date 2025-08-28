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
*/