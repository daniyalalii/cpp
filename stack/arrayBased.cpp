#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void print(){
        if(top==-1){
            cout<<"Empty"<<endl;
            return;
        }
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void push(int val){
        if(top>99){
            cout<<"OverFlow"<<endl;
            return;
        }
        
        arr[++top] = val;
    }

    void pop(){
        if(top==-1){
            cout<<"UnderFlow"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top==-1){
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    Stack st;
    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }
    st.pop();
    st.print();
    return 0;
}