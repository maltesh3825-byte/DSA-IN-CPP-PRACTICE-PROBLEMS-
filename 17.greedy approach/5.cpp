//max chain length
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
void maxChainLength(vector<pair<int,int>> pairs){
    
    sort(pairs.begin(),pairs.end(),compare);
    int currend=pairs[0].second;
    int ans=1;
    int n=5;
    for(int i=1;i<=n;i++){
        if(pairs[i].first>currend){
            ans++;
            currend=pairs[i].second;
        }
    }
    cout<<"max chain length : "<<ans<<endl;


}
int main(){
    int n=5;
    vector<pair<int ,int>> pairs(n,make_pair(0,0));
    pairs[0]=make_pair(5,24);
    pairs[0]=make_pair(39,60);
    pairs[0]=make_pair(5,28);
    pairs[0]=make_pair(27,40);
    pairs[0]=make_pair(50,90);
    maxChainLength(pairs);
   
}