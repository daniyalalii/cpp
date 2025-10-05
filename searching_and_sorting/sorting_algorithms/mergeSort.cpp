#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid,int right);

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left )/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid +1, right);
    merge(arr,left,mid,right);
}

void merge(int arr[], int left, int mid,int right){
    int n1 = mid - left +1;
    int n2 = right - mid;
    int* leftarr = new int[n1];
    int* rightarr = new int[n2];
    for(int i =0; i<n1; i++){
        leftarr[i] = arr[left + i];
    }
    for(int j =0; j<n2; j++){
        rightarr[j] = arr[mid + 1 + j];
    }
    int i =0, j=0, k= left;
    while(i<n1 && j<n2){
        if(leftarr[i] <= rightarr[j]){
            arr[k] = leftarr[i];
            i++;
        }
        else{
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = leftarr[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = rightarr[j];
        j++; k++;
    }
    delete[] leftarr;
    delete[] rightarr;
}

int main()
{
    int arr[] = {9, 8, 1, 3, 2, 5, 7, 6, 4};
    cout << "Before: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, size - 1);
    cout << "After: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}