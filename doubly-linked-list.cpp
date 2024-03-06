#include <iostream>
#include <cassert>
using namespace std;

// null <- |prev|val|next| -> <- |prev|val|next| -> <- |prev|val|next| -> null
template<class T> struct Node {
    Node *prev;
    T val;
    Node *next;
    // constructor
    Node(Node *prev, T val, Node *next): prev(prev), val(val), next(next) {};
};

template<class T> class LinkedList{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addFront(T val) {
        if (head == nullptr) {
            head = new Node<T>(nullptr, val, nullptr);
            tail = head;
        } else {
            Node<T>* newNode = new Node<T>(nullptr, val, head);
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void deleteFront(){
        assert(head != nullptr);
        Node<T>* tmp = head;
        head = head->next;
        head->prev = nullptr;
        tmp->next = nullptr;
        delete tmp;
        size--;
    }
    void addBack(T val) {
        if (tail == nullptr) {
            tail = new Node<T>(nullptr, val, nullptr);
            head = tail;
        } else {
            Node<T>* newNode = new Node<T>(tail, val, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void deleteBack(){
        assert(tail != nullptr);
        Node<T>* tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        tmp->prev = nullptr;
        delete tmp;
        size--;
    }
    void addAtPosition (T val, int idx){
        assert(idx < size + 1);
        if (idx == 0) {
            addFront(val);
            return;
        }
        if (idx == size - 1) {
            addBack(val);
            return;
        }
        // find the prev of index
        Node<T> *prev = head;
        for(int i = 0; i < idx - 1 && prev != nullptr; i++){
            prev = prev->next;
        }
        // find the next of index
        Node<T> *next = prev->next;
        Node<T> *newNode = new Node(prev, val, next);
        if (next != nullptr) {
            next->prev = newNode;
        } else {
            tail = newNode;
        }
        prev->next = newNode;
        size++;
    }

    int getElement(int idx){
        assert(idx < size);
        Node<T> *cur = head;
        if(idx == 0){
            return cur->val;
        }
        if(idx == size - 1){
            return tail->val;
        }
        for(int i = 0; i < idx && cur != nullptr; i++){
            cur = cur->next;
        }
        return cur->val;
    }

    void deleteElement(int idx){
        assert(idx < size);
        Node<T> *cur = head;
        if(idx == 0){
            deleteFront();
            return;
        }
        if(idx == size - 1){
            deleteBack();
            return;
        }
        for(int i = 0; i < idx && cur != nullptr; i++){
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->prev = nullptr;
        cur->next = nullptr;
        delete cur;
        size--;
    }

    void display(){
        Node<T> *cur = head;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    void reverse(){ //
        if (head == tail) {
            return;
        }
        Node<T> *cur = tail;
        Node<T> *nxt;
        Node<T> *prv = nullptr;
        while(cur != nullptr){
            nxt = cur->prev;
            cur->prev = prv;
            cur->next = nxt;

            prv = cur;
            cur = nxt;
        }
        head = tail;
        tail = prv; //
    }

    bool isEmpty(){
        return head == tail;
    }

    int getSize(){
        return size;
    }


};
int main() {
    LinkedList<int> link;
    cout << "Before Insert any element: \n";
    cout << "Is Empty? " << (link.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << link.getSize() << endl;

    link.addFront(1);
    link.addFront(5);
    link.addFront(6);
    link.addBack(4);
    link.addAtPosition(8, 1);

    cout << "\nAfter Insert elements: \n";
    cout << "Is Empty? " << (link.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << link.getSize() << endl;
    cout << "Elements: ";
    link.display();
    cout << "Elements Reversed: ";
    link.reverse();
    link.display();

    cout << "\nThe element at position 2 *(zero based)*: " << link.getElement(2) << endl;

    cout << "\nThe first element before delete: " << link.getElement(0) << endl;
    link.deleteFront();
    cout << "The first element after delete: " << link.getElement(0) << endl;

    cout << "\nThe last element before delete: " << link.getElement(link.getSize() - 1) << endl;
    link.deleteBack();
    cout << "The last element after delete: " << link.getElement(link.getSize() - 1) << endl;

    cout << "\nElements: ";
    link.display();
    cout << "The element at position 1 before delete: " << link.getElement(1) << endl;
    link.deleteElement(1);
    cout << "Elements: ";
    link.display();
    cout << "The element at position 1 after delete: " << link.getElement(1)<< endl;

    // 6 8 5 1 4
    return 0;
}