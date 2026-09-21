//memory allocation for vectors
#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector <int> v1={1,2,3,4};
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;
    
    v1.push_back(5);
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;

    v1.pop_back();
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;

}