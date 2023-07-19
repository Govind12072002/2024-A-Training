
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Stack {
    int *a;
    int Top;
    int capacity;
public:
    Stack(int size) {
        Top = -1;
        capacity = size;
    }

    void push(int val) {
        if(isFull()) {
            cout << "OVERFLOW : Value " << val << " can't be pushed in stack as stack is full." << endl;
            return;
        }

        ++Top;
        a[Top] = val;
    }

    void pop() {
        if(isEmpty()) {
            cout << "UNDERFLOW : Stack is empty." << endl;
            return;
        }
        --Top;
    }

    int top() { 
        if(isEmpty()) {
            cout << "UNDERFLOW : Can't fetch top of stack as stack is empty. RETURNING -1...." << endl;
            return -1;
        }
        return a[Top]; 
    }

    int size() { return Top+1; }

    bool isEmpty() {
        return Top == -1;
    }

    bool isFull() {
        return Top+1 == capacity;
    }

    void printStack() {
        if(isEmpty()) {
            cout << "UNDERFLOW : Stack is empty." << endl;
            return;
        }

        for(int i=0 ; i<=Top ; ++i) cout << a[i] << " ";
        cout << "<- TOP" << endl;
    }
};

int main() {
    // Stack of size 10
    Stack s(10);
    
    cout << "is stack empty : " << (s.isEmpty() ? "True" : "False") << endl;
    cout << "is stack full : " << (s.isFull() ? "True" : "False") << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.push(110);
    s.printStack();

    cout << "is stack empty : " << (s.isEmpty() ? "True" : "False") << endl;
    cout << "is stack full : " << (s.isFull() ? "True" : "False") << endl;
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.printStack();
    cout << "is stack empty : " << (s.isEmpty() ? "True" : "False") << endl;
    cout << "is stack full : " << (s.isFull() ? "True" : "False") << endl;

    cout << endl << "Stack size : " << s.size() << endl;
    cout << "Stack Top : " << s.top() << endl;

    return 0;
}