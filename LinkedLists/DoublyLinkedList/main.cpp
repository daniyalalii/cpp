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

void printForward(Node* head){
    if(head==NULL) return;
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* getTail(Node* head){
    if(head==NULL) return NULL;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

void printBackward(Node* head){
    if(head==NULL) return;
    Node* tail = getTail(head);
    while(tail!=NULL){
        cout<<tail->data<<" <-> ";
        tail = tail->prev;
    }
    cout<<"NULL"<<endl;
}

void printBidirectional(Node* head){
    if(head==NULL) return;
    Node* temp = head;
    Node* tail = NULL;
    cout<<"Forward: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        if(temp->next==NULL) tail = temp;
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<"Backward: "<<endl;
    while(tail!=NULL){
        cout<<tail->data<<" <-> ";
        tail = tail->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = new Node(1);
    Node* node1 = new Node(4);
    Node* node2 = new Node(7);
    Node* node3 = new Node(9);
    Node* tail = new Node(0);
    head->prev = NULL;
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = tail;
    tail->prev = node3;
    tail->next = NULL;

    printBidirectional(head);

    return 0;
}
