//static keyword use for class
#include<iostream>
using namespace std;
class Example{
public:
    static int x;
};
int Example::x=0;
int main(){
    Example e1,e2,e3;
    cout<<e1.x++;
    cout<<e2.x++;
    cout<<e3.x++;
    return 0;
}