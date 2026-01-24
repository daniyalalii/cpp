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
    if(!head) return;
    Node* temp = head;
    cout<<"NULL <- ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* getTail(Node* head){
    if(!head) return nullptr;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* left = head;
    Node* right = getTail(head);
    while(left!=right && left->prev!=right){
        if(left->data!=right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main(){
    Node* head = new Node(1);
    Node* node1 = new Node(3);
    Node* node2 = new Node(3);
    Node* node3 = new Node(1);
    // Node* tail = new Node(1);
    
    head->prev = NULL;
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;
    // node3->next = tail;
    // tail->prev = node3;
    // tail->next = NULL;

    printList(head);

    if(isPalindrome(head)){
        cout<<"List is palindrome"<<endl;
    }
    else{
        cout<<"List is not palindrome"<<endl;
    }
    return 0;
}