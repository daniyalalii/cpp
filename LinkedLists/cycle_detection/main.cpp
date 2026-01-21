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

Node* cycleStart(Node* head){
    if(head==NULL) return NULL;
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }

    if(fast==NULL || fast->next==NULL) return NULL;

    slow = head;
    while(slow!=head){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeCycle(Node* head){
    Node* start = cycleStart(head);

    if(start == NULL) return;
    Node* temp = start;
    while(temp->next!=start){
        temp = temp->next;
    }
    temp->next = NULL;
}

int countCycleLength(Node* head){
    if(head==NULL) return 0;

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            int count = 1;
            fast = fast->next;
            while(slow!=fast){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
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
    Node* start = cycleStart(head);
    cout<<"Cycle starts and Node: "<<start->val<<endl;
    int length = countCycleLength(head);
    cout<<"Length of the cycle is: "<<length<<endl;
    cout<<"Removing the cycle: "<<endl;
    removeCycle(head);
    }
    
    
    printList(head);
    return 0;
}