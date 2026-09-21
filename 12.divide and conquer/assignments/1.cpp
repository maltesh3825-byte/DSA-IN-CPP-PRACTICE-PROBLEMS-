#include<iostream>
#include<string>
#include<vector>
using namespace std;
void mix(string s1[],int si,int ei,int mid){
    if(si>=ei){
        return;
    }
    int i=si;
    int j = mid+1;
    vector <string> s2; 
    while(i<=mid&&j<=ei){
        if(s1[i]<s1[j]){
            s2.push_back(s1[i++]);
        }
        else{
            s2.push_back(s1[j++]);

        }
    }
    while(i<=mid){
        s2.push_back(s1[i++]);
    }
    while(j<=ei){
        s2.push_back(s1[j++]);
    }
    for(int idx=si,i=0;idx<=ei;idx++){
        s1[idx]=s2[i++];
    }
}
void merge(string s1[],int si,int ei){
    if(si>=ei){
        return ;
    }
    int mid=si+(ei-si)/2;
    merge(s1,si,mid);
    merge(s1,mid+1,ei);

    mix(s1,si,ei,mid);
}
void print(string s1[],int n){
    for(int i=0;i<n;i++){
        cout<<s1[i]<<" ";
    }
}
int main(){
    int n=4;
    string s1[n]={"sun","earth","mars","mercury"};
    merge(s1,0,n-1);
    print(s1,n);
    return 0;
}
    