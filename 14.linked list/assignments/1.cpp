//check for palindrome//lc 234
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;

    List() {
        head = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    bool isPalindrome() {
        if(head == NULL || head->next == NULL) return true;

        // 1. find middle
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse second half
        Node* prev = NULL;
        Node* curr = slow;
        Node* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. compare both halves
        Node* first = head;
        Node* second = prev;

        while(second != NULL) {
            if(first->data != second->data) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    ll.print();

    if(ll.isPalindrome()) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
} 