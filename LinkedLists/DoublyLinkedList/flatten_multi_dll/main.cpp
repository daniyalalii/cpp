#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* child;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
        child = NULL;
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

Node* flatten(Node* head){
    if(!head) return NULL;
    Node* curr = head;
    while(curr){
        if(curr->child){
            Node* nextNode = curr->next;
            Node* childHead = curr->child;
            childHead->prev = curr;
            curr->child = NULL;

            curr->next = childHead;

            Node* tail = childHead;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = nextNode;
            if(nextNode){
                nextNode->prev = tail;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    Node* child1 = new Node(7);
    Node* node3 = new Node(8);
    Node* child2 = new Node(11);
    Node* node4 = new Node(12);
    Node* tail = new Node(4);

    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = tail;
    tail->prev = node2;
    node2->child = child1;
    child1->prev = node2;
    child1->next = node3;
    node3->prev = child1;
    node3->child = child2;
    child2->prev = node3;
    child2->next = node4;
    node4->prev = child2;

    Node* res = flatten(head);
    printList(res);

    return 0;
}



