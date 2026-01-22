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

void deleteNthNode(Node *&head, int n)
{
    Node dummy;
    dummy.next = head;
    Node *slow = &dummy;
    Node *fast = &dummy;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        Node *del = slow->next;
        slow->next = del->next;
        delete del;
        head = dummy.next;
    
}

int main()
{
    Node *head = new Node{1, nullptr};
    Node *sec = new Node{2, nullptr};
    Node *th = new Node{3, nullptr};
    Node *fr = new Node{4, nullptr};
    Node *fv = new Node{2, nullptr};
    Node *sx = new Node{1, nullptr};

    head->next = sec;
    sec->next = th;
    th->next = fr;
    fr->next = fv;
    fv->next = sx;

    printList(head);
    int input;
    cout << "Which nth node you want to delete" << endl;
    cin >> input;

    deleteNthNode(head, input);

    printList(head);
    return 0;
}