#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

struct Deque{
    Node* front;
    Node* rear;
    Deque(){
        front = rear = NULL;
    }
};

void pushFront(Deque& dq, int val){
    Node* n = new Node(val);
    if(!dq.front){
        dq.front = dq.rear = n;
        return;
    }
    n->next = dq.front;
    dq.front->prev = n;
    dq.front = n;
}

void pushBack(Deque& dq, int val){
    Node* n = new Node(val);
    if(!dq.front){
        dq.front = dq.rear = n;
        return;
    }
    dq.rear->next = n;
    n->prev = dq.rear;
    dq.rear = n;
}

void popFront(Deque& dq){
    if(!dq.front) return;
    Node* temp = dq.front;
    if(dq.front==dq.rear){
        dq.front = dq.rear = NULL;
    }
    else{
        dq.front = temp->next;
        dq.front->prev = NULL;
        delete temp;
    }
}

void popBack(Deque& dq){
    if(!dq.rear) return;
    Node* temp = dq.rear;
    if(dq.front==dq.rear){
        dq.front = dq.rear = NULL;
    }
    else{
        dq.rear = temp->prev;
        dq.rear->next = NULL;
        delete temp;
    }
}

int getFront(Deque& dq){
    if(!dq.front){
        cout<<"Empty Deque"<<endl;
        return -1;
    }
    return dq.front->data;
}

int getBack(Deque& dq){
    if(!dq.rear){
        cout<<"Empty list"<<endl;
        return -1;
    }
    return dq.rear->data;
}

void printDeque(Deque& dq){
    if(!dq.front) {
        cout<<"Empty List"<<endl;
        return;
    }
    Node* temp = dq.front;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Deque deq;
    pushFront(deq, 5);
    pushBack(deq,10);
    pushBack(deq, 15);
    pushFront(deq,0);
    printDeque(deq);

    cout<<"Poping front front and rear"<<endl;
    popFront(deq);
    popBack(deq);
    printDeque(deq);
    
    // popBack(deq);
    // popBack(deq);

    cout<<"First element of deq: "<<getFront(deq)<<endl;
    cout<<"Last element of deq: "<<getBack(deq)<<endl;
}
