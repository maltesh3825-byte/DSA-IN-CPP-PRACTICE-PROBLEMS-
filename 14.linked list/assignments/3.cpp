//delete m nodes after  n  nodes
#include<iostream> 
#include<list> 
#include<iostream>
using namespace std;
void deleteNodes(list<int> &l,int n,int m){
    list<int>::iterator it=l.begin();
    while(it!=l.end()){
        for(int i =0;i<m-1 && it!=l.end();i++){
            it++;
        }
        if(it==l.end()){
            break;
        }

        auto start=next(it);
        for(int i=0;i<n && start!=l.end();i++){
            start=l.erase(start);
        }
        it=start;
    }
}

void printll(list<int> &l){
    auto it=l.begin();
    for(int i=0;i<l.size();i++){
        cout<<*it;
        it++;
        if(it!=l.end()){
            cout<<"->";
        }
       
    }
}
int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    deleteNodes(l,2,2);
    printll(l);
    return 0;
} 