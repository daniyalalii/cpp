#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front, rear, size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = val;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    void print(){
        if(isEmpty()) {
            cout<<"Queue is empty\n";
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue q(5);
    if (q.isEmpty())
        cout << "Empty\n";
    else
        cout << "Not empty\n";
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    if (q.isFull())
        cout << "full\n";
    else
        cout << "Not full\n";
    q.dequeue();
    cout << q.peek() << endl;
    q.print();

    return 0;
}