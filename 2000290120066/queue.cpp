
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Queue {
    int *a;
    int front = 0, back = -1;
    int capacity;
    int size;
    
public:
    Queue(int k) {
        a = new int[k];
        front = 0;
        back = -1;
        size = 0;
        capacity = k;
    }

    ~Queue() { delete a; }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }
    int getSize() { return size; }

    int getFront() {
        if(isEmpty()) {
            cout << "UNDERFLOW : Can't fetch front of Queue as Queue is Empty. RETURNING -1...." << endl;
            return -1;
        }

        return a[front];
    }
    int getBack() {
        if(isEmpty()) {
            cout << "UNDERFLOW : Can't fetch back of Queue as Queue is Empty. RETURNING -1...." << endl;
            return -1;
        }

        return a[back];
    }

    void enqueue(int val) {
        if(isFull()) {
            cout << "OVERFLOW : Value " << val << " can't be enqueued in queue as queue is full." << endl;
            return;
        }

        back = (back + 1) % capacity;
        ++size;
        a[back] = val;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "UNDER : Queue is empty." << endl;
            return;
        }

        front = (front + 1) % capacity;
        --size;
    }

    void printQueue() {
        if(isEmpty()) {
            cout << "UNDERFLOW : Can't print, Queue is empty." << endl;
            return;
        }

        int t = size, i = front;
        cout << "Front -> ";
        while(t) {
            cout << a[i] << " ";
            i = (i + 1) % capacity;
            --t;
        }
        cout << "<- Back" << endl;
    }
};

int main() {
    Queue q(10);
    
    cout << "Is queue empty : " << (q.isEmpty() ? "True" : "False") << endl;
    cout << "Is queue full : " << (q.isFull() ? "True" : "False") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    q.enqueue(110);

    q.printQueue();
    cout << "Is queue empty : " << (q.isEmpty() ? "True" : "False") << endl;
    cout << "Is queue full : " << (q.isFull() ? "True" : "False") << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.printQueue();
    cout << "Is queue empty : " << (q.isEmpty() ? "True" : "False") << endl;
    cout << "Is queue full : " << (q.isFull() ? "True" : "False") << endl;

    cout << endl << "Queue Size : " << q.getSize() << endl;
    cout << "Queue Front : " << q.getFront() << endl;
    cout << "Queue Back : " << q.getBack() << endl;

    return 0;
}