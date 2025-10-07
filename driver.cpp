#include "ArrayStack.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& s){
    cout << "Before rotate" << endl;
    cout << s;

    s.rotate(Stack<T>::RIGHT);
    cout << "After rotate RIGHT" << endl;
    cout << s;

    s.rotate(Stack<T>::LEFT);
    cout << "After rotate LEFT" << endl;
    cout << s;
}

int main(){
    ArrayStack<int> si(5);
    si.push(10);
    si.push(20);
    si.push(30);
    si.push(40);
    si.push(50);
    testRotate(si);

    ArrayStack<char> sc(4);
    sc.push('a');
    sc.push('b');
    sc.push('c');
    sc.push('d');
    testRotate(sc);

    ArrayStack<string> ss(3);
    ss.push(string("alpha"));
    ss.push(string("beta"));
    ss.push(string("gamma"));
    testRotate(ss);

    ArrayStack<int> emptyS(2);
    try {
        emptyS.peek();
    } catch (string& e) {
        cout << e << endl;
    }
    try {
        emptyS.pop(); 
    } catch (string& e) {
        cout << e << endl;
    }
    try {
        emptyS.push(1);
        emptyS.push(2);
        emptyS.push(3);
    } catch (string& e) {
        cout << e << endl;
    }
    return 0;
}