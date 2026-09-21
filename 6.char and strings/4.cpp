#include<iostream>
#include<string>
using namespace std;

bool equal(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    int count[26] = {0};   // frequency array

    // Count characters of s1
    for(int i = 0; i < s1.length(); i++){
        count[s1[i] - 'a']++;
    }

    // Subtract using s2
    for(int i = 0; i < s2.length(); i++){
        if(count[s2[i] - 'a'] == 0){
            return false;
        }
        count[s2[i] - 'a']--;
    }

    return true;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << equal(s1, s2);
    return 0;
}