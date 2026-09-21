//0-1 triangle pattern
#include<iostream>
using namespace std;
int main()
{
    int i,j,n=5;
    bool val=true;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<val<<" ";
            val=!val;
        }
        cout<<endl;
    }
    return 0;
}
