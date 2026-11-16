// Q1 - Call by value, reference and pointer: hostel fee concession
#include <iostream>
using namespace std;
void byValue(long long fee, int percent) { fee -= fee * percent / 100; }
void byReference(long long& fee, int percent) { fee -= fee * percent / 100; }
void byPointer(long long* fee, int percent) { if (fee != nullptr) *fee -= *fee * percent / 100; }
long long returnedFee(long long fee, int percent) { return fee - fee * percent / 100; }
int main() {
    long long valueFee=45000, refFee=45000, ptrFee=45000;
    byValue(valueFee,10); byReference(refFee,10); byPointer(&ptrFee,10);
    cout << "After value: " << valueFee << '\n';
    cout << "After reference: " << refFee << '\n';
    cout << "After pointer: " << ptrFee << '\n';
    cout << "Returned fee: " << returnedFee(45000,10) << '\n';
    int a=1,b=2,c=3;
    auto change=[](int x,int& y,int* z){ x+=10; y+=10; if(z) *z+=10; };
    change(a,b,&c);
    cout << "Predict-output variables: " << a << ' ' << b << ' ' << c << '\n';
    auto bigger=[](int& p,int& q)->int& { return p>q?p:q; };
    bigger(a,c)=100;
    cout << "After bigger: " << a << ' ' << c << '\n';
}
