//unordered maps and maps
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    unordered_map<string,int> m;
    map<string,int> m2;
    m["india"]=170;
    m["china"]=50;
    m["us"]=50;
    m["nepal"]=10;

    for(pair<string,int> c : m){
        cout<<c.first<<","<<c.second<<endl;
    }
   cout<<"\n"<< m.size();

    m.erase("us");
    cout<<"\n"<< m.size();
    m["india"]=180;
     for(pair<string,int> c : m){
        cout<<c.first<<","<<c.second<<endl;
    }
    if(m.count("india")==1){
        cout<<"exists";
    }
    else{
        cout<<"not exists";
    }

    cout<<"\n----------------\nmap\n";
    //map
    m2["india"]=170;
    m2["china"]=50;
    m2["us"]=50;
    m2["nepal"]=10;

    for(pair<string,int> c : m2){
        cout<<c.first<<","<<c.second<<endl;
    }
    cout<<"\n"<< m2.size();

    m2.erase("us");
     for(pair<string,int> c : m2){
        cout<<c.first<<","<<c.second<<endl;
    }
    cout<<"\n"<< m2.size();
    m2["india"]=180;
    if(m2.count("india")==1){
        cout<<"exists";
    }
    else{
        cout<<"not exists";
    }


    return 0;

}