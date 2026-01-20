#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void printList(Node* head){
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverseLinkedList(Node*& head){
    if(head==NULL) return head;
    Node* current = head;
    Node* prev = NULL;
    while(current!=NULL){
        Node* next = current->next;
        current->next = prev;
        prev= current;
        current = next;
    }
    return prev;
}

int main(){
    Node* first = new Node{1,nullptr};
    Node* second = new Node{2,nullptr};
    Node* third = new Node{3,nullptr};

    first->next = second;
    second->next = third;

    printList(first);

    first = reverseLinkedList(first);

    printList(first);

        while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    return 0;
}