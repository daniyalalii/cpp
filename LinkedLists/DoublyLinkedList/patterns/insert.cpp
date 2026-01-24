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

void printList(Node* head){
    if(head==NULL) return;
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAfter(Node* x,int val){
    if(!x) return;
    Node* n = new Node(val);
    n->next = x->next;
    n->prev = x;
    if(x->next!=NULL){
        x->next->prev = n;
    }
    x->next = n;
}

void insertBefore(Node* x,int val){
    if(!x) return;
    Node* n = new Node(val);
    n->prev = x->prev;
    n->next = x;
    if(x->next!=NULL){
        x->prev->next = n;
    }
    x->prev = n;
}

int main(){
    Node* head = new Node(1);
    Node* node1 = new Node(3);
    Node* node2 = new Node(5);
    Node* node3 = new Node(9);
    Node* tail = new Node(11);
    
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
    
    cout<<"Before adding node: "<<endl;
    printList(head);
    insertAfter(node2,7);
    cout<<"Adding node 7 after node 2"<<endl;
    printList(head);
    cout<<"Adding node 0 before node1"<<endl;
    insertBefore(node1,0);
    printList(head);
    return 0;
}