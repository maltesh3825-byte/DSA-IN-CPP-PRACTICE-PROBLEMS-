//Count how many times lower case vowels occurred in a String entered by the user

#include<iostream>
#include<cstring>
using namespace std;
int countlo(string str){
    int count=0;
    for(int i =0;i<str.length();i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            count++;
        }
    }
    
    return count;

}
int main(){
    string str;
    getline(cin,str);
    cout<<"lowercase count = "<<countlo(str);

}