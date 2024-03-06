#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

template <class T> class Stack{
private:
    int n, max_size;
    T *arr;

public:
    Stack(){
        max_size = 1;
        n = 0;
        arr = new T[max_size];
    }

    void push(T val){
        if(n == max_size){
            max_size *= 2;
            T *newArr = new T[max_size];
            for(int i = 0; i < n; i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
        }
        arr[n++] = val;
    }

    void pop(){
        assert(n != 0);
        n--;
        if(2*n == max_size){
            max_size /= 2;
            T *newArr = new T[max_size];
            for(int i = 0; i < n; i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
        }
    }

    T top(){
        assert(n != 0);
        return arr[n - 1];
    }

    bool isEmpty(){
        return n == 0;
    }

    int getSize(){
        return n;
    }
};
int main() {
    Stack<int> s;
    cout << "Before Insert any element: \n";
    cout << "Is Empty? " << (s.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << s.getSize() << endl;

    s.push(4);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(1);
    s.push(2);
    s.push(5);
    s.pop();
    cout << s.top() << endl;

    cout << "After Inserting: \n";
    cout << "Is Empty? " << (s.isEmpty() ? "YES\n" : "NO\n");
    cout << "Size: " << s.getSize() << endl;

    return 0;
}