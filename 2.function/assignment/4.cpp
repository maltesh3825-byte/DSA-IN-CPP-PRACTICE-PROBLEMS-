//estion4:Writeafunctionthatprintsthelargestof3numbers
#include<iostream>
using namespace std;
int lar(int a,int b, int c){
    if(a>b){
        if(a>c){
            return a;
        }
        else{
            return c;
        }

    }
    else if(b>c){
        return b;
    }
    else if(c>a&&c>b){
        return c;
    }
    else {
        cout<<"enter unequal values!";
    }
    return 0;

}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<lar(a,b,c);
    return 0;
}
