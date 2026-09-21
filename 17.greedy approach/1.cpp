//activity selection
#include <iostream>
#include <vector>
using namespace std;
int selection(vector<int> start,vector<int> end){
    cout<<"selecting A0\n";
    int count=1;
    int currendTime=end[0];
    for(int i=0;i<start.size();i++){
        if(start[i]>=currendTime){
            cout<<"selecting A"<<i<<"\n";
            count++;
            currendTime=end[i];
        }
    }
    return count;
}
int main(){
    vector<int> st={1,3,0,5,8,5};
    vector<int> en={2,4,6,7,9,9};
    cout<<selection(st,en)<<endl;
    return 0;
}