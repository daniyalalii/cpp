#include<iostream>
using namespace std;

long int RecursiveSum(int arr[],int start, int size, int sum){
    if(start==size){
        return sum;
    }
    else{
        sum = sum + arr[start];
        return RecursiveSum(arr,start+1,size,sum);
    }
}

int main(){
    int size;
    do{
        cout<<"Enter the size for array:(greater than 0) "<<endl;
        cin>>size;
    }while(size<=0);
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the value for array at index: "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<RecursiveSum(arr,0,size,0);
    return 0;
}