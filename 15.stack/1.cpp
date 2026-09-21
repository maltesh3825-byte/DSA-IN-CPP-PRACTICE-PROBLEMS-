//stack implementation using vector
#include <iostream>
#include <vector>
using namespace std;

// Defining a Class Template
template <class T>
class Stack {
    vector<T> vec; // The vector will now hold elements of type T
    
public:
    // Push element onto the stack
    void push(T val) {
        vec.push_back(val);
    }
    
    // Remove the top element
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        vec.pop_back();
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return vec.size() == 0;
    }
    
    // Get the top element
    T top() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            // Returns the default value of type T (e.g., 0 for int, empty string for string)
            return T(); 
        }
        int maxIdx = vec.size() - 1;
        return vec[maxIdx];
    }
     void print (){
        while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    }
};

int main() {
    // Instantiating an integer stack using the template
    Stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);
    
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}