// Q6 - Friend and inline functions for train journey times
#include <iostream>
#include <cstdlib>
using namespace std;
class Time{ int h,m; public: Time(int hh,int mm):h(hh),m(mm){ if(h<0||h>23||m<0||m>59){h=0;m=0;} } friend int minutesBetween(const Time&,const Time&); friend bool earlier(const Time&,const Time&); };
inline int minutesBetween(const Time& a,const Time& b){ return abs((a.h*60+a.m)-(b.h*60+b.m)); }
inline bool earlier(const Time& a,const Time& b){ return a.h<b.h||(a.h==b.h&&a.m<b.m); }
int main(){ Time departure(9,45),arrival(13,10); cout<<minutesBetween(departure,arrival)<<' '<<boolalpha<<earlier(arrival,departure)<<'\n'; Time beforeNoon(11,55),afterNoon(12,10); cout<<minutesBetween(beforeNoon,afterNoon)<<' '<<earlier(beforeNoon,afterNoon)<<'\n'; Time sameA(14,5),sameB(14,5); cout<<minutesBetween(sameA,sameB)<<' '<<earlier(sameA,sameB)<<'\n'; }
