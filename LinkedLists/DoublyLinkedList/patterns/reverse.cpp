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
// dll wrapper
struct doublyLL{
    Node* head;
    Node* tail;
    doublyLL(){
        head = NULL;
        tail = NULL;
    }
};

void insertAtHead(doublyLL& list, int val){
    Node* n = new Node(val);
    if(!list.head){
        list.head = list.tail = n;
        return;
    }
    n->next = list.head;
    list.head->prev = n;
    list.head = n;
}

void insertAtTail(doublyLL& list, int val){
    Node* n = new Node(val);
    if(!list.head){
        list.head = list.tail = n;
        return;
    }
    n->prev = list.tail;
    list.tail->next = n;
    list.tail = n;
}

void printList(doublyLL& list){
    Node* temp = list.tail;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

void reverseList(doublyLL& list){
    if(!list.head || !list.head->next) return;
    Node* temp = NULL;
    Node* curr = list.head;
    while(curr!=NULL){
        temp = curr->next;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    temp = list.head;
    list.head = list.tail;
    list.tail = temp;
}



int main(){
    doublyLL list;
    insertAtHead(list,1);
    insertAtHead(list,2);
    insertAtTail(list,3);
    insertAtTail(list,4);
    insertAtTail(list,5);
    printList(list);
    cout<<"reversing the list"<<endl;
    reverseList(list);
    printList(list);

    return 0;
}