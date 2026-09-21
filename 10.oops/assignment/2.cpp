#include<iostream>
using namespace std;
class BankAccount{
    int Accountnum;
    int balance=0;
public:
    BankAccount(int acc,int bal){
        Accountnum=acc;
        balance=bal;
    }
    void ShowBalance(){
        cout<<balance<<endl;
    }
    void Deposit(int depamo){
        balance+=depamo;
    }
    void withdraw(int witamo){
        balance-=witamo;
    }
};
int main(){
    BankAccount myAcc(1234,500);
    myAcc.ShowBalance();
    myAcc.Deposit(200);
    myAcc.withdraw(100);
    myAcc.ShowBalance();
    return 0;
}