//Question1:WriteafunctiontocheckifanumberisapalindromeinC++.(121isapalindrome,321isnot)Anumberiscalledapalindromeifthenumberisequaltothereverseofanumber.Eg:121isapalindromebecausethereverseof121is121itself.Ontheotherhand,321isnotapalindromebecausethereverseof321is123,whichisnotequalto321
#include<iostream>
using namespace std;
int rev(int n){
    int lastdig,res=0;
    while(n>0){
        lastdig= n%10;
        res= res*10 +lastdig;
        n=n/10;
        
    }
    return res;
}
bool ispali(int num){
    return num== rev(num);
}
int main()
{
    cout<<ispali(1221)<<endl;
    return 0;
}