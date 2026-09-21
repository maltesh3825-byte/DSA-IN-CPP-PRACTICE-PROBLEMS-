//reverse a char array
#include<iostream>
#include<cstring>
using namespace std;
void rev(char *word,int n){
    int st=0,end=n-1;
    while(st<end){
        swap(word[st++],word[end--]);
    }

}

int main(){
    char word[]="code";
    rev(word,strlen(word));
    cout<<"reverse = "<<word;
    return 0;
}