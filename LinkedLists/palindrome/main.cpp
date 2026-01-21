#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* reverseList(Node* head){
    if(head==NULL) return NULL;

    Node* cur = head;
    Node* prev = NULL;

    while(cur!=NULL){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL) return true;

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;
    Node* temp = secondHalf;

    while(temp!=NULL){
        if(firstHalf->val!=temp->val) return false;
        temp = temp->next;
        firstHalf= firstHalf->next;
    }
    return true;
}

int main(){
    Node* head = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* fr = new Node{4,nullptr};
    Node* fv = new Node{2,nullptr};
    Node* sx = new Node{1,nullptr};

    head->next = sec;
    sec->next = th;
    th->next = fr;
    fr->next = fv;
    fv->next = sx;
    if(isPalindrome(head)){
        cout<<"Link list is Palindrome"<<endl;
    }
    else{
        cout<<"List is not Palindrome"<<endl;
    }
    return 0;
}