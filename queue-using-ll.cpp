#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

template<class T> struct Node {
    T val;
    Node *next;
    // constructor
    Node(T val, Node *next): val(val), next(next) {};
};

template<class T> class Queue{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    void push(T val) {
        if (tail == nullptr) {
            tail = new Node<T>(val, nullptr);
            head = tail;
        } else {
            Node<T>* newNode = new Node<T>(val, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void pop(){
        assert(head != nullptr);
        Node<T>* tmp = head;
        head = head->next;
        tmp->next = nullptr;
        delete tmp;
        size--;
    }
    T front(){
        assert(tail != nullptr);
        return head->val;
    }

    bool isEmpty(){
        return tail == head;
    }

    int getSize(){
        return size;
    }


};
int main() {
    Queue<int> q;
    cout << "Before Insert any element: \n";
    cout << "Is Empty? " << (q.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << q.getSize() << endl;

    q.push(4);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(1);
    q.push(2);
    q.push(5);
    q.pop();
    cout << q.front() << endl;

    // (4) -(3)- 1 (2) -5-
    
    return 0;
}