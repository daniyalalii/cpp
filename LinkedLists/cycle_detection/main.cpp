#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void printList(Node* head){

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool detectCycle(Node* head){
    if(head==NULL) return true;
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return false;
    }
    return true;
}

int main(){
    Node* head = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* fr = new Node{4,nullptr};
    Node* fv = new Node{5,nullptr};
    Node* sx = new Node{6,nullptr};

    head->next = sec;
    sec->next = th;
    th->next = fr;
    fr->next = fv;
    fv->next = sx;
    sx->next = head;

    if(detectCycle(head)){
        cout<<"List does not contain cycle"<<endl;
    }
    else{
        cout<<"there cycle in the list"<<endl;
    }

    printList(head);
    return 0;
}