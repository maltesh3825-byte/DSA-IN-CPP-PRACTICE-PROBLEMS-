//unordered sets and sets
#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    for(auto e :s){
        cout<<e<<endl;
    }
    if(s.find(3)!=s.end()){
        cout<<"3 exists"<<endl;
    }
    else{
        cout<<"3 not exists"<<endl;
    }

    s.erase(3);
    
    if(s.find(3)!=s.end()){
        cout<<"3 exists"<<endl;
    }
    else{
        cout<<"3 not exists"<<endl;
    }

    cout<<s.size();
    //same code for set
    //set<int> s2;
    //.............
    return 0;
}