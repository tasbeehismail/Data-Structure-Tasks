#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

#define SIZE 20

template <class T> class Queue{
private:
    int n;
    T *arr;
    int frontIdx, rearIdx;

public:
    Queue(){
        n = 0;
        arr = new T[SIZE];
        frontIdx = 0;
        rearIdx = 0;
    }

    void push(T val){
        if(n == 0){
            arr[rearIdx] = val;
            n++;
            return;
        }
        rearIdx = (rearIdx + 1) % SIZE;
        arr[rearIdx] = val;
        n++;
    }

    void pop(){
        assert(n != 0);
        frontIdx = (frontIdx + 1) % SIZE;
        n--;
    }

    T front(){
        assert(n != 0);
        return arr[frontIdx];
    }

    bool isEmpty(){
        return n == 0;
    }

    int getSize(){
        return n;
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

    cout << "After Inserting: \n";
    cout << "Is Empty? " << (q.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << q.getSize() << endl;


    return 0;
}