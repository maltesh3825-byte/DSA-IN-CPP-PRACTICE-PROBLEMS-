//union and intersection
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void printunion(vector<int> v1,vector<int> v2){
    unordered_set<int> s;
    for(auto e:v1){
        s.insert(e);
    }
    for(auto e:v2){
        s.insert(e);
    }
    for(auto e:s){
        cout<<e<<" ";
    }
    cout<<endl;
}


void printintersection(vector<int> v1,vector<int> v2){
    unordered_set<int> s;
    for(auto e:v1){
        s.insert(e);
    }
    for(auto e:v2){
        if(s.find(e)!=s.end()){
            cout<<e<<" ";
            s.erase(e);
        }
    }
    cout<<endl;
}
int main(){
    vector<int> arr1={7,3,9};
    vector<int> arr2={6,3,9,2,9,4};
    printunion(arr1,arr2);
    printintersection(arr1,arr2);
    return 0;
}