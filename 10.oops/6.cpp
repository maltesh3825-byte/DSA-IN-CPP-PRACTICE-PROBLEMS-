//abstraction
#include<iostream>
using namespace  std;
class shape{
public:
    virtual void draw() = 0;
};
class circle:public shape{
public:
    void draw(){
        cout<<"circle draw\n";
    }
};
class square:public shape{
public:
    void draw(){
        cout<<"square draw\n";
    }
};
int main(){
    circle c1;
    c1.draw();
    square s1;
    s1.draw();
    return 0;       
}
