#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    static int count;
    Node() { count++; }
    ~Node()
    {
        count--;
    }
};
int Node::count = 0;

int getTotalNodes()
{
    return Node::count;
}

void printList(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    cout << "HEAD";
    while (temp != NULL)
    {
        cout << " -> " << temp->val;
        temp = temp->next;
    }
    // cout<<temp->val<<" -> ";
    cout << " -> NULL" << endl;
    cout << "Total Nodes: " << Node::count << endl;
}

void insertAtStart(Node *&head, int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node *&head, int val, int pos)
{
    if (pos == 1)
    {
        insertAtStart(head, val);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp!=NULL; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromStart(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteByValue(Node *&head, int val)
{
    if (head == NULL)
        return;
    if (head->val == val)
    {
        deleteFromStart(head);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->val != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

void searchVal(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == val)
        {
            cout << "Value is present in list" << endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Value is not present in the list"<<endl;
}

int main()
{
    Node *head = NULL;

    cout << "=== Singly Linked List Operations ===" << endl;

    // Insert operations
    cout << "1. Inserting elements at start (5, 3, 1):" << endl;
    insertAtStart(head, 5);
    insertAtStart(head, 3);
    insertAtStart(head, 1);
    printList(head);
    cout << endl;

    cout << "2. Inserting elements at end (7, 9):" << endl;
    insertAtEnd(head, 7);
    insertAtEnd(head, 9);
    printList(head);
    cout << endl;

    cout << "3. Inserting element 4 at position 3:" << endl;
    insertAtPosition(head, 4, 3);
    printList(head);
    cout << endl;

    // Search operations
    cout << "4. Searching for value 7:" << endl;
    searchVal(head, 7);
    cout << endl;

    cout << "5. Searching for value 100 :" << endl;
    searchVal(head, 100);
    cout << endl;

    // Delete operations
    cout << "6. Deleting from start:" << endl;
    deleteFromStart(head);
    printList(head);
    cout << endl;

    cout << "7. Deleting from end:" << endl;
    deleteAtEnd(head);
    printList(head);
    cout << endl;

    cout << "8. Deleting value 4:" << endl;
    deleteByValue(head, 4);
    printList(head);
    cout << endl;

    cout << "9. Final list:" << endl;
    printList(head);
    cout << endl;

    cout << "Total nodes created: " << getTotalNodes() << endl;

    return 0;
}