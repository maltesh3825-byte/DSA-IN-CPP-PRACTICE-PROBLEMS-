//job seequence variation
//job sequencing problem 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Job{
public:
    int profit;
    int idx;
    int deadline;

    Job(int idx,int profit,int deadline){
        this->idx=idx;
        this->profit=profit;
        this->deadline=deadline;

    }
};
int maxProfit(vector<pair<int,int>> pair){
    int n=4;
    vector<Job> jobs;
    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pair[i].second,pair[i].first);
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b ){
        return a.profit>b.profit;
    });
    
    
    cout<<"selecting job: J"<<jobs[0].idx<<endl;

    int deadline=jobs[0].idx+1;
    int profit=jobs[0].profit;
    for(int i=1;i<n;i++){
        if(jobs[i].deadline>deadline){
            cout<<"selecting job: J"<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            deadline=jobs[i].deadline+1;
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