#include<iostream>
#include<vector>
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

Node* mergeTwo(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->val<b->val){
        a->next = mergeTwo(a->next,b);
        return a;
    }
    else{
        b->next = mergeTwo(a,b->next);
        return b;
    }
}

Node* mergeK(vector<Node*>& lists, int l, int r){
    if(l>r) return nullptr;
    if(l==r) return lists[l];
    int mid = l + (r-l) / 2;
    Node* left = mergeK(lists,l,mid);
    Node* right = mergeK(lists,mid+1,r);
    return mergeTwo(left,right);
}

Node* mergeKlists(vector<Node*> lists){
    if(lists.empty()) return nullptr;
    return mergeK(lists,0,lists.size()-1);
}

int main(){
    Node* head1 = new Node{1,nullptr};
    Node* node1 = new Node{2,nullptr};
    Node* node2 = new Node{5,nullptr};
    Node* head2 = new Node{3,nullptr};
    Node* node3 = new Node{4,nullptr};
    Node* head3 = new Node{0, nullptr};
    Node* node4 = new Node{6,nullptr};
    head1->next = node1;
    node1->next = node2;
    head2->next = node3;
    head3->next = node4;

    vector<Node*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    cout<<"list1"<<endl;
    printList(head1);
    cout<<"list2"<<endl;
    printList(head2);
    cout<<"list3"<<endl;
    printList(head3);

    cout<<"after merging"<<endl;
    Node* merge = mergeKlists(lists);
    printList(merge);

    return 0;
}