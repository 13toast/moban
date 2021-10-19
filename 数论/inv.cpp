#include <bits/stdc++.h>
using namespace std;

void exgcd(int a,int b,int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	exgcd(b,a%b,y,x);
	y -= (a / b) * x;
}
long long inv[200005];
void get_inv(long long p) {
	inv[1] = 1;
	for (int i=2;i<=n;++i) {
		inv[i] = (long long)(p - p/i) * inv[p%i] % p;
	}
}
int main() {

	return 0;
}