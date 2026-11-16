#include <iostream>
#include <chrono>
using namespace std;
volatile long long sinkValue=0;
inline int inlineCalc(int x){return (x*3+7)%997;}
#if defined(__GNUC__)
__attribute__((noinline))
#endif
int noInlineCalc(int x){return (x*3+7)%997;}
template<class F> double run(F fn,int n){ auto start=chrono::steady_clock::now(); long long sum=0; for(int i=0;i<n;++i)sum+=fn(i); sinkValue=sum; auto end=chrono::steady_clock::now(); return chrono::duration<double,milli>(end-start).count(); }
int main(){ constexpr int N=10000000; cout<<"inline_ms "<<run(inlineCalc,N)<<'\n'; cout<<"noinline_ms "<<run(noInlineCalc,N)<<'\n'; cout<<"sink "<<sinkValue<<'\n'; }
