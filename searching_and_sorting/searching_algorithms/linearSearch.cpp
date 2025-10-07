#include<iostream>
using namespace std;
bool linearSearch(int arr[], int size, int input){
    for(int i=0;i<size;i++){
        if(arr[i]==input){
            return true;
        }
    }
    return false; 
}

int main(){
    int arr[] = {5,4,6,7,8,2,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int input;
    cout<<"Enter the number you want to find: "<<endl;
    cin>>input;
    if(linearSearch(arr,size,input)){
        cout<<"Number found in the array!"<<endl;
    }
    else{
        cout<<"Number not found in the array!"<<endl;
    }
    return 0;
}