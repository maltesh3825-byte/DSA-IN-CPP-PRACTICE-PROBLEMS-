//map in c++
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m;
    m[65]="mallu";
    m[66]="maltesh";
    m[67]="kulal";

    for(auto i:m){
        cout<<i.first<<" : "<<i.second<<endl;
    }
    return 0;
}
