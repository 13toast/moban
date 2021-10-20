#include <bits/stdc++.h>
using namespace std;
int n,a[100005],LOG[100005];
int st[100005][25];
int MAX(int a, int b) {return a>b?a:b;}
void getLOG(int a) {
	LOG[1] = 0;
	for (int i=2;i<=n;i++) LOG[i] = LOG[i>>1] + 1;
}
int query(int l, int r) {
	int k = LOG[r-l+1];
	return MAX(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
	cin>>n;
	getLOG(n);
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		st[i][0] = a[i];
	}
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = MAX(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int a,b,c;
	cin>>a>>b;
	c = query(a,b);
	return 0;
}