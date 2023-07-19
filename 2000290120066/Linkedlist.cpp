
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node *head;
    int length;

public:
    LinkedList() {
        head = NULL;
        length = 0;
    }

    void insertNode(int);
    void printNodes();
    void deleteNode(int);
    int getLength() { return length; }
};

void LinkedList::insertNode(int data) {
    if(!head) {
        head = new Node(data);
        ++length;
        return;
    }

    Node *tmp = head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = new Node(data);
    ++length;
}

void LinkedList::printNodes() {
    if(!head) {
        cout << "UNDERFLOW :: List is empty !!!" << endl;
        return;
    }

    Node *node = head;
    while(node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void LinkedList::deleteNode(int pos) {
    if(!head) {
        cout << "UNDERFLOW :: List is empty !!!" << endl;
        return;
    }

    if(length < pos) {
        cout << "OUT OF RANGE :: Given position is out of range !!!" << endl;
        return;
    }

    Node *tmp = head;
    if(pos == 1) {
        head = head->next;
        delete tmp;
        --length;
        return;
    }

    Node* tmp2;
    while(pos-- > 1) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = tmp->next;
    delete tmp;
    --length;
}

int main() {
    LinkedList list;
    
    list.printNodes();
    cout << "Length of LinkedList : " << list.getLength() << endl;
    
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);

    list.printNodes();

    list.deleteNode(4);
    list.deleteNode(6);

    list.printNodes();
    cout << "Length of LinkedList : " << list.getLength() << endl;

    return 0;
}