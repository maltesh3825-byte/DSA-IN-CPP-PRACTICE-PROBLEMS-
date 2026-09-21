//Question3:Writeafunctionwhichtakes2numbersasparameters(a&b)andoutputs:a^2+b^2+2*ab
#include<iostream>
using namespace std;
int sq(int a,int b)
{
    int s=((a*a)+(b*b)+(2*a*b));
    return s;
}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    cout<<sq(a,b);
    return 0;
}