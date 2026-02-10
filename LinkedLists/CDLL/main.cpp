#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val = 0){
        data = val;
        next = prev = NULL;
    }
};

void printForward(Node* head){
    if(!head) {
        cout<<"Empty"<<endl;
        return;
    }

    Node* temp = head;
    do{
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

void printBackward(Node* head){
    if(!head){
        cout<<"Empty"<<endl;
        return;
    }

    Node* temp = head->prev;
    do{
        cout<<temp->data<<" <-> ";
        temp = temp->prev;
    }while(temp!=head->prev);
    cout<<endl;
}

Node* insertEmpty(int val){
    Node* newNode = new Node(val);

    newNode->next = newNode;
    newNode->prev = newNode;

    return newNode;
}

Node* insertAtHead(Node* head, int val){
    if(!head){
        Node* newNode = insertEmpty(val);
        return newNode;
    }   

    Node* tail = head->prev;
    Node* newHead = new Node(val);
    
    newHead->next = head;
    newHead->prev = tail;
    tail->next = newHead;
    head->prev = newHead;

    return newHead;
}

Node* insertAtTail(Node* head, int val){
    if(!head){
        Node* newNode = insertEmpty(val);
        return newNode;
    } 

    Node* tail = head->prev;
    Node* newTail = new Node(val);

    newTail->next = head;
    head->prev = newTail;
    newTail->prev = tail;
    tail->next = newTail;
    
    return head;
}

Node* deleteHead(Node* head){
    if(head->next==head){
        delete head;
        return nullptr;
    }

    Node* tail = head->prev;
    Node* newHead = head->next;
    
    tail->next = newHead;
    newHead->prev = tail;

    delete head;
    return newHead;
}

Node* deleteTail(Node* head){
    if(head==head->next){
        delete head;
        return nullptr;
    }

    Node* tail = head->prev;
    Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    delete tail;
    return head;
}

int main(){
    Node* head = insertEmpty(10);

    printForward(head);
    head = insertAtHead(head, 20);
    head = insertAtTail(head, 30);
    printBackward(head);

    head = deleteHead(head);
    printForward(head);
    head = deleteTail(head);
    printForward(head);

    delete head;
    return 0;
}   