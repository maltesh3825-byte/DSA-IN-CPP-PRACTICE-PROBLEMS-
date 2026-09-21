//Youaregiventwostringss1ands2ofequallength.Astringswapisanoperationwhereyouchoosetwoindicesinastring(notnecessarilydifferent)andswapthecharactersattheseindices.
#include<iostream>
#include<string>
using namespace std;
bool equal(string s1,string s2){
    
    if(s1.length() != s2.length()){
        return false;
    }
    int count =0;
    char d1=0,d2=0;
   for(int i = 0;i<s1.length();i++){
    if(s1[i]!=s2[i]){
        count++;
        
        if(count==1){
            d1=s1[i];
            d2=s2[i];
        }
        else if(count==2){
            if(s1[i]!=d2 || s2[i]!=d1){
                return 0;
            }
            
        }
        else{
            return 0;
        }
        
    }

   }
   if(count==1){
    return 0;
   }
   return true;
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<equal(s1,s2);
    return 0 ;
}