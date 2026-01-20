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
    cout<<" NULL"<<endl;
}

Node* findMiddle(Node* head){
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node* head = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* fr = new Node{4,nullptr};
    Node* fv = new Node{5,nullptr};
    Node* sx = new Node{6,nullptr};
    // Node* sv = new Node{7,nullptr};

    head->next = sec;
    sec->next = th;
    th->next = fr;
    fr->next = fv;
    fv->next = sx;
    // sx->next = sv;

    printList(head);

    Node* middle = findMiddle(head);

    cout<<"Middle node's value is: "<<middle->val;
    return 0;
}