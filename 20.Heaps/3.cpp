#include<iostream>
#include<queue>
using namespace std;
class Student{
   
public:
    int marks;
    string name;

    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }
    
    //custom comparator
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }
};
int main(){
    priority_queue <Student>pq;
    pq.push(Student("ajay",78));
    pq.push(Student("lisa",99));
    pq.push(Student("kia",47));

    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}