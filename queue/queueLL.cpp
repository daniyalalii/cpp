#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue(){
        front = rear = nullptr;
    }
    
    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int val){
        Node* newNode = new Node(val);
        if(front == nullptr){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if(front == NULL){
            rear = NULL;
        }
    }

    void print(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp = front;
        while(temp!=rear){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<rear->data<<endl;
    }

    void peek(){
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<front->data<<endl;
        }
    }
};

int main(){
    Queue q;
    if(q.isEmpty()) cout<<"Queue is empty\n";
    else cout<<"Queue is not empty\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();
    q.peek();
    q.dequeue();
    q.print();
    return 0;
}