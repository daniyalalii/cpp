// find length
// make ll cycle/circular
// break at right point

#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void printList(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* rotate(Node* head, int k){
    if(!head || !head->next || k==0) return head;

    int length = 1;
    Node* curr = head;
    while(curr->next){
        curr = curr->next;
        length++;
    }
    k = k % length;
    curr->next = head;
    
    int step = length - k;
    while(step--) curr = curr->next;
    Node* newHead = curr->next;
    curr->next = nullptr;
    return newHead;
}

int main(){
    Node* head = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* sx = new Node{6,nullptr};
    Node* sv = new Node{7,nullptr};

    head->next = sec;
    sec->next = th;
    th->next = sx;
    sx->next = sv;
    printList(head);
    Node* newHead = rotate(head,2);
    printList(newHead);
    return 0;
}