#include<iostream>
using namespace std;
class Person{
protected:
    string name;
    int age;    
public:
    
    Person(string n,int a){
        name = n;
        age = a;
    }
};
class Student :public Person{
    int stdid;
public:
    Student(string name,int age,int sid):Person(name,age){
        stdid =sid;
    }
    void DisplayStudentInfo(){
        cout<<"name = "<<name<<endl;
        cout<<"age = "<<age<<endl;
        cout<<"student id = "<<stdid<<endl  ;


    }
};
int main (){
    Student s1("jhatsaab",18,66);
    s1.DisplayStudentInfo();
    return 0;
}
