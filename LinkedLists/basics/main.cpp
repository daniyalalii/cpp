#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *link;
};

int main(){
    Node *head;
    Node* current = head;
    while(current!=NULL){
        cout<<current->val<<" ";
        current = current->link;
    }
    return 0;
}