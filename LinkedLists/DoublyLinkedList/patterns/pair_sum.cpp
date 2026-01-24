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
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* getTail(Node* head){
    if(!head) return NULL;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

void pairCheck(Node* head,int target){
    if(!head) return;
    Node* left = head;
    Node* right = getTail(head);
    while(left!=right && left->prev!=right){
        int sum = left->data + right->data;
        if(sum==target){
            cout<<"( "<<left->data<<" , "<<right->data<<" )"<<endl;
            left = left->next;
            right = right->prev;
        }
        else if(sum<target){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }
}

int main(){
    Node* head = new Node(1);
    Node* node1 = new Node(2);
    Node* node2 = new Node(4);
    Node* node3 = new Node(5);
    Node* node4 = new Node(6);
    Node* tail = new Node(8);
    
    head->prev = NULL;
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = tail;
    tail->prev = node4;
    tail->next = NULL;

    printList(head);

    pairCheck(head,7);

    return 0;
}