// Q2 - Return by reference, const reference, copy and dangling-reference warning
#include <iostream>
#include <algorithm>
using namespace std;
int& highestMark(int marks[],int n){ int index=0; for(int i=1;i<n;++i) if(marks[i]>marks[index]) index=i; return marks[index]; }
const int& readHighest(const int marks[],int n){ static int snapshot=0; snapshot=*max_element(marks,marks+n); return snapshot; }
int highestCopy(const int marks[],int n){ return *max_element(marks,marks+n); }
// Deliberately not called: returning a reference to a local object is undefined behaviour.
int& dangerousLocalReference(){ int local=99; return local; }
int main(){ int marks[]={72,88,91,84,91}; int n=sizeof(marks)/sizeof(marks[0]);
 cout<<"Highest before: "<<highestMark(marks,n)<<'\n'; highestMark(marks,n)=93;
 cout<<"Highest after moderation: "<<highestMark(marks,n)<<'\n';
 const int& view=readHighest(marks,n); int copy=highestCopy(marks,n);
 cout<<"Const-reference view: "<<view<<'\n'<<"Returned copy: "<<copy<<'\n'<<"Array: ";
 for(int x:marks) cout<<x<<' '; cout<<'\n'; }
