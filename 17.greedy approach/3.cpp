//fractional knapsnack
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
int fractionalKnapsnack(vector<int>val,vector<int>wt,int W){
    int n=val.size();
    vector<pair<double,int>> ratio(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    //sorting desecendingly
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx = ratio[i].second;
        if(wt[idx]<W){
            ans+=val[idx];
            W-=wt[i];
        }
        else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    cout<<"maimum total value : "<<ans<<endl;
}
int main(){
    vector <int>val={60,100,120};
    vector <int>wt={10,20,30};
    int W=50;
    fractionalKnapsnack(val,wt,W);
    return 0;
}