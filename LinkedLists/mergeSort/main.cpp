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

Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->val<b->val){
        a->next = merge(a->next,b);
        return a;
    }
    else{
        b->next = merge(a,b->next);
        return b;
    }
}

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(second);
    return merge(left,right);
}

int main(){
    Node* headA = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* sx = new Node{6,nullptr};
    Node* sv = new Node{7,nullptr};

    headA->next = sv;
    sv->next = th;
    th->next = sx;
    sx->next = sec;
    printList(headA);
    Node* res = mergeSort(headA);
    printList(res);
    printList(headA);
    return 0;
}