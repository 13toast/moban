#include<bits/stdc++.h>
#include <time.h>
using namespace std;
int Count_One(int x) {
    x = (x&0x55555555)+((x>>1)&0x55555555);
    x = (x&0x33333333)+((x>>2)&0x33333333);
    x = (x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
    x = (x&0x00FF00FF)+((x>>8)&0x00FF00FF);
    x = (x&0x0000FFFF)+((x>>16)&0x0000FFFF);
    return x;
}
int main() {
    clock_t _start,_end;
	_start = clock();
    for (int i=1;i<=44040192;++i) Count_One(i);
    _end = clock();
	cout << "time = " << double(_end-_start) / CLOCKS_PER_SEC << endl;
    return 0;
}