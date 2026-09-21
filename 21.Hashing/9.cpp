//union and intersection
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void itinerery(unordered_map<string,string> tickets){
    unordered_set<string> to;
    for(pair<string,string> tic:tickets){
        to.insert(tic.second);
    }
    string start="";
    for(pair<string,string> tic:tickets){
        if(to.find(tic.first)==to.end()){
            start=tic.first;
        }
    }

    cout<<"start"<<"->";
    cout<<start<<"->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"->";
        start=tickets[start];
    }
    cout<<"end"<<endl;
}
int main(){
   unordered_map<string,string>t;
   t["chennai"]="benglur";
   t["mumbai"]="deli";
   t["goa"]="chennai";
   t["deli"]="goa";
   itinerery(t);

    return 0;
}