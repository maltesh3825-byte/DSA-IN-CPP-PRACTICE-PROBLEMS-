//circular queue using arrays
#include<iostream>
using namespace std;
class Queue{
    int* arr;
    int capacity;
    int currsize;
    int f,r;
public:
    Queue(int capcity){
        this->capacity=capcity;
        arr=new int [capacity];
        currsize=0;
        f=0;
        r=-1;
    }
    void push(int data){
        if(currsize==capacity){
            cout<<"queue is FULL\n";
            return;
        }
        r=(r+1)%capacity;
        arr[r]=data;
        currsize++;
    }
    void pop(){
        if(empty()){
            cout<<"queue is empty\n";
            return;
        }
        f=(f+1)%capacity;
        currsize--;

    }
    int front(){
        if(empty()){
            cout<<"queue is empty\n";
            return 0;
        }
        return arr[f];


    }
    bool empty(){
        return currsize==0;
    }
};
int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front();
    q.pop();
    q.push(5);
   cout<< q.front();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.front();


}