#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int s = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"Enter the element you want to find in the array: "<<endl;
    cin>>key;
    int index = binarySearch(arr,s,key);
    if(index!=-1){
        cout<<"Element found at index: "<<index<<endl;
    }
    else{
        cout<<"Element not found in the array!"<<endl;
    }
    return 0;
}