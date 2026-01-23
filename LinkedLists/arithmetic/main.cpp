#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void printList(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *addTwo(Node *l1, Node *l2)
{
    Node dummy;
    Node *curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new Node({sum % 10});
        curr = curr->next;
    }
    return dummy.next;
}

int main()
{
    Node *head1 = new Node{1, nullptr};
    Node *node1 = new Node{2, nullptr};
    Node *node2 = new Node{5, nullptr};
    Node *head2 = new Node{3, nullptr};
    Node *node3 = new Node{4, nullptr};
    Node *node4 = new Node{6, nullptr};
    head1->next = node1;
    node1->next = node2;
    head2->next = node3;
    node3->next = node4;

    printList(head1);
    printList(head2);
    Node* res = addTwo(head1,head2);
    printList(res);

    return 0;
}