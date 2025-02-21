
#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

class MinHeap {
    int *a;
    int maxSize;
    int heapSize;

    int parent(int i) { return ((i-1) >> 1); }
    int leftChild(int i) { return (i<<1) + 1; }
    int rightChild(int i) { return (i<<1) + 2; }

    void minHeapify(int i) {
        int l = leftChild(i), r = rightChild(i);
        int smallest = i;

        if(l < heapSize && a[l] < a[smallest]) smallest = l;
        if(r < heapSize && a[r] < a[smallest]) smallest = r;

        if(smallest != i) {
            swap(a[i], a[smallest]);
            minHeapify(smallest);
        }
    }

public:
    MinHeap(int size) {
        heapSize = 0;
        maxSize = size;
        a = new int[size];
    }

    int removeMin() {
        if(heapSize <= 0) return INT_MIN;
        if(heapSize == 1) return a[--heapSize];

        int root = a[0];
        a[0] = a[--heapSize];

        minHeapify(0);

        return root;
    }

    void increaseKey(int i, int newVal) {
        if(i < 0 || i >= heapSize) {
            cout << "INVALID INPUT INDEX : Enter a valid index between 0 to " << (heapSize - 1) << '.' << endl;
            return;
        }

        a[i] = newVal;

        while(i != 0 && a[parent(i)] > a[i]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    int getMin() { return a[0]; }
    int size() { return heapSize; }
    int capacity() { return maxSize; }

    void deleteKey(int i) {
        if(i < 0 || i >= heapSize) {
            cout << "INVALID INPUT INDEX : Enter a valid index between 0 to " << (heapSize - 1) << '.' << endl;
            return;
        }

        increaseKey(i, INT_MIN);
        removeMin();
    }

    void insertKey(int val) {
        if(heapSize == maxSize) {
            cout << "OVERFLOW : Heap is Full. Value " << val << " can't be insert." << endl;
            return;
        }

        int i = heapSize++;
        a[i] = val;

        while(i != 0 && a[parent(i)] > a[i]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void printHeap() {
        if(heapSize == 0) {
            cout << "UNDERFLOW : Heap is empty. Can't be printed." << endl;
            return;
        }

        cout << "Heap Content : " << endl;
        for(int i=0 ; i<heapSize ; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(30);
    h.insertKey(40);
    h.insertKey(50);
    h.insertKey(60);
    h.insertKey(70);
    h.insertKey(80);
    h.insertKey(90);
    h.insertKey(100);
    h.insertKey(110);

    cout << endl;
    h.printHeap();
    cout << endl;

    h.deleteKey(-1);
    h.deleteKey(4);

    cout << endl;
    h.printHeap();
    cout << endl;

    cout << "Size of heap : " << h.size() << endl;
    cout << "Capacity of heap : " << h.capacity() << endl;
    cout << "Min of heap : " << h.getMin() << endl;
    cout << endl;

    h.increaseKey(12, 110);
    h.increaseKey(3, 110);

    cout << endl;
    h.printHeap();
    cout << endl;

    cout << "Value " << h.removeMin() << " is removed and fetched from heap." << endl;

    cout << "Size of heap : " << h.size() << endl;
    cout << "Capacity of heap : " << h.capacity() << endl;
    cout << "Min of heap : " << h.getMin() << endl;
    cout << endl;

    return 0;
}