//palindrome check
#include<iostream>
#include<cstring>
using namespace std;
bool pal(char *word,int n){
    int st=0,end=n-1;
    while(st<end){
        if(word[st]!=word[end]){
            cout<<"not palindrome\n";
            return false;
        }
        st++;
        end--;


    }
    cout<<"palindrome\n";
    return true;
}

int main(){
        char word[]="modam";
        pal(word,strlen(word));
        return 0;
}