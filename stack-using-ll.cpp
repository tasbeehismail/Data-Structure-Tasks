#include <iostream>
#include <cassert>
using namespace std;

// null <- |val|next| -> <- |val|next| -> <- |val|next| -> null
template<class T> struct Node {
    T val;
    Node *next;
    // constructor
    Node(T val, Node *next): val(val), next(next) {};
};

template<class T> class Stack{
private:
    Node<T> *head;
    int size;
public:
    Stack() : head(nullptr), size(0) {}

    void push(T val) {
        if (head == nullptr) {
            head = new Node<T>(val, nullptr);
        } else {
            Node<T>* newNode = new Node<T>(val, head);
            head = newNode;
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

    T top(){
        assert(head != nullptr);
        return head->val;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int getSize(){
        return size;
    }


};
int main() {
    Stack<int> s;
    cout << "Before Insert any element: \n";
    cout << "Is Empty? " << (s.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << s.getSize() << endl;

    s.push(5);
    s.push(3);
    s.push(2);
    cout << "\nThe top of stack: " << s.top() << endl;
    s.pop();
    cout << "The top of stack: " << s.top() << endl;
    s.push(1);
    s.push(4);
    s.pop();
    cout << "The top of stack: " << s.top() << endl;

    cout << "\nAfter Push: \n";
    cout << "Is Empty? " << (s.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << s.getSize() << endl;

    // 4 1 3 5
    return 0;
}