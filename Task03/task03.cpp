// Q3 - Default arguments and unambiguous function overloading
#include <iostream>
#include <iomanip>
using namespace std;
struct Parcel{ double weightKg; bool express; bool insured; };
double priceKg(double kg,bool express=false,bool insured=false){ double total=kg*50.0; if(express) total+=30.0; if(insured) total+=20.0; return total; }
double charge(int grams){ return priceKg(grams/1000.0); }
double charge(double kg,bool express=false,bool insured=false){ return priceKg(kg,express,insured); }
double charge(const Parcel& p){ return priceKg(p.weightKg,p.express,p.insured); }
void show(const char* label,double amount){ cout<<label<<": Rs "<<fixed<<setprecision(2)<<amount<<'\n'; }
int main(){ Parcel p{2.5,true,true}; show("charge(2) [int grams]",charge(2)); show("charge(2.0) [double kg]",charge(2.0)); show("charge(2.0f) [float to double]",charge(2.0f)); show("charge(2000) [int grams]",charge(2000)); show("charge(2.0, true)",charge(2.0,true)); show("charge(Parcel)",charge(p)); }
