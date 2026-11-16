// Q5 - Static members, seat allocation and arrays of objects
#include <iostream>
#include <string>
using namespace std;
class BusTicket{ static int issued; static const int CAPACITY=3; int seat; string name;
public: explicit BusTicket(const string& n):seat(0),name(n){ if(issued<CAPACITY) seat=++issued; }
 static int count(){return issued;} void print() const{ cout<<name<<": "<<(seat?"Seat "+to_string(seat):"Waiting")<<'\n'; } };
int BusTicket::issued=0;
class Token{ static int next; int id; public: Token():id(++next){} int get()const{return id;} static int issued(){return next-100;} };
int Token::next=100;
void createTwoMore(){ BusTicket a("Function-A"),b("Function-B"); a.print(); b.print(); cout<<"Cumulative issued: "<<BusTicket::count()<<'\n'; }
int main(){ Token counter[3]; Token extra; cout<<"Token prediction: "<<counter[0].get()<<' '<<counter[2].get()<<' '<<extra.get()<<' '<<Token::issued()<<'\n';
 BusTicket trip[4]={BusTicket("Asha"),BusTicket("Bala"),BusTicket("Chitra"),BusTicket("Dev")}; for(const BusTicket& t:trip)t.print(); cout<<"Issued: "<<BusTicket::count()<<'\n'; createTwoMore(); }
