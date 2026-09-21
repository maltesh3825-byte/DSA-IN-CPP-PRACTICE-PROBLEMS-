//job sequencing problem 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int>p2){
    return p1.second>p2.second;
}
int maxProfit(vector<pair<int,int>> job){
    int n=4;
    sort(job.begin(),job.end(),compare);
    int deadline=job[0].first+1;
    int profit=job[0].second;
    for(int i=1;i<n;i++){
        if(job[i].first>deadline){
            profit+=job[i].second;
            deadline=job[i].first+1;
        }
    }
    
    cout<<"max profit from jobs: "<<profit<<endl;
    return profit;
}
int main(){
    vector<pair<int,int>> job(4,make_pair(0,0));
    job[0]=make_pair(4,20);
    job[1]=make_pair(1,10);
    job[2]=make_pair(1,40);
    job[3]=make_pair(1,30);
    maxProfit(job);
    return 0;
}