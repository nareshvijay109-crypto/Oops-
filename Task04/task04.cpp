// Q4 - SavingsAccount with fixed circular transaction history
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class SavingsAccount{ string accountNumber; long long balancePaise; long long transactions[10]{}; int count=0,next=0;
public: SavingsAccount(const string& number,long long openingPaise):accountNumber(number),balancePaise(openingPaise){}
 void deposit(long long amountPaise); bool withdraw(long long amountPaise); void miniStatement() const; long long balance() const{return balancePaise;} };
void SavingsAccount::deposit(long long amountPaise){ if(amountPaise<=0)return; balancePaise+=amountPaise; transactions[next]=amountPaise; next=(next+1)%10; if(count<10)++count; }
bool SavingsAccount::withdraw(long long amountPaise){ if(amountPaise<=0||amountPaise>balancePaise)return false; balancePaise-=amountPaise; transactions[next]=-amountPaise; next=(next+1)%10; if(count<10)++count; return true; }
void SavingsAccount::miniStatement() const{ cout<<"Account: "<<accountNumber<<"\nLast "<<count<<" transactions:\n"; int start=(count==10)?next:0; for(int i=0;i<count;++i){ long long amount=transactions[(start+i)%10]; cout<<(amount>=0?"Deposit ":"Withdraw ")<<"Rs "<<fixed<<setprecision(2)<<(amount>=0?amount:-amount)/100.0<<'\n'; } cout<<"Balance: Rs "<<fixed<<setprecision(2)<<balancePaise/100.0<<'\n'; }
int main(){ SavingsAccount account("SA1001",100000); for(int i=1;i<=11;++i) account.deposit(i*1000); account.withdraw(5000); account.miniStatement(); }
