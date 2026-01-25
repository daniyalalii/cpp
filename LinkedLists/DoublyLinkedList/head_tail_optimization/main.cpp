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
    Node* temp = list.head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteHead(doublyLL& list){
    if(!list.head) return;
    Node* temp = list.head;
    if(list.head==list.tail){
        list.head = list.tail = NULL;
    }
    else{
        list.head = temp->next;
        list.head->prev = NULL;
        delete temp;
    }
}

void deleteTail(doublyLL& list){
    if(!list.tail) return;
    Node* temp = list.tail;
    if(list.head == list.tail){
        list.head = list.tail = NULL;
    }
    else{
        list.tail = temp->prev;
        list.tail->next = NULL;
        delete temp;
    }
}

void deleteNode(doublyLL& list, Node* x){
    if(!x) return;
    if(x==list.head) list.head = x->next;
    if(x==list.tail) list.tail = x->prev;
    if(x->prev) x->prev->next = x->next;
    if(x->next) x->next->prev = x->prev;
    delete x;
}


int main(){
    doublyLL list;
    insertAtHead(list,1);
    insertAtHead(list,2);
    insertAtTail(list,3);
    insertAtTail(list,4);
    insertAtTail(list,5);
    printList(list);
    cout<<"Deleting head"<<endl;
    deleteHead(list);
    printList(list);
    cout<<"Deleting tail"<<endl;
    deleteTail(list);
    printList(list);
    Node* mid = list.head->next;
    cout<<"Deleting mid node"<<endl;
    deleteNode(list,mid);
    printList(list);
    return 0;
}