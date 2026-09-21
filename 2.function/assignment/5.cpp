//Question5:Writeafunctionthatacceptsacharacter(ch)asparameters&returnsthecharacterthatoccursafterchintheEnglishalphabet.Eg:input=‘c’,returnvalue=‘d’Note:forch=‘z’,return‘a’
#include<iostream>
using namespace std;
char al(char a){
    if(int(a)==122){
        return 97;
    }
    else{
        return (int(a)+1);
    }
}
int main(){
    char a;
    cin>>a;
    cout<<al(a);
    return 0;
}
