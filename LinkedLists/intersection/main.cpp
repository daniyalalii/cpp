#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* intersection(Node* headA, Node* headB){
    Node* a = headA;
    Node* b = headB;
    while(a!=b){
        a = (a==nullptr)? headB : a->next;
        b = (b==nullptr)? headA : b->next;
    } 
    return a;
}

int main(){
    Node* headA = new Node{1, nullptr};
    Node* sec = new Node{2,nullptr};
    Node* th = new Node{3,nullptr};
    Node* sx = new Node{6,nullptr};
    Node* sv = new Node{7,nullptr};

    headA->next = sec;
    sec->next = th;
    th->next = sx;
    sx->next = sv;


    Node* headB = new Node{4,nullptr};
    Node* fv = new Node{4,nullptr};

    headB->next = fv;
    // fv->next = sx;

    Node* intersec = intersection(headA,headB);
    cout<<"Intersection: "<<intersec<<endl;
    return 0;
}
