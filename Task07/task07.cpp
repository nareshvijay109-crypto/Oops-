// Q7 - Diagnose and redesign: shift-array history vs circular buffer
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
class ShiftHistory{ vector<int> data; int capacity; public: explicit ShiftHistory(int k):capacity(k){} void add(int value){ if((int)data.size()==capacity)data.erase(data.begin()); data.push_back(value); } int sum()const{int s=0;for(int x:data)s+=x;return s;} };
class CircularHistory{ vector<int> data; int capacity,count=0,next=0; public: explicit CircularHistory(int k):data(k),capacity(k){} void add(int value){data[next]=value;next=(next+1)%capacity;if(count<capacity)++count;} int sum()const{int s=0;for(int i=0;i<count;++i)s+=data[i];return s;} };
int main(){ constexpr int K=50,N=1000000; ShiftHistory oldDesign(K); CircularHistory revised(K); auto a=chrono::steady_clock::now(); for(int i=0;i<N;++i)oldDesign.add(i); auto b=chrono::steady_clock::now(); for(int i=0;i<N;++i)revised.add(i); auto c=chrono::steady_clock::now(); cout<<"Last-50 sums equal: "<<boolalpha<<(oldDesign.sum()==revised.sum())<<'\n'; cout<<"Shift design milliseconds: "<<chrono::duration<double,milli>(b-a).count()<<'\n'; cout<<"Circular design milliseconds: "<<chrono::duration<double,milli>(c-b).count()<<'\n'; long long expected=0; for(int i=N-K;i<N;++i)expected+=i; cout<<"Expected last-50 sum: "<<expected<<'\n'; }
