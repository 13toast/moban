#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mst(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for (int i=a;i<=b;++i)

using namespace std;

const int MAXN = 100001;
int prime[MAXN],phi[MAXN];
bool vis[MAXN];

void euler() {

}
int main() {
	int t; cin >> t;
	euler();
	rep(_,1,t) {
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if (k == 0 || k > b || k > d) {
			printf("Case %d: 0\n",_);
			continue;
		}
		b /= k;
		d /= k;
		if (b > d) swap(b,d);
		long long ans = 0;
		rep(i,1,b) {
			ans += phi[i];
		}
		rep(i,b+1,d) {
			ans += cal(i,b);
		}
	} 
	return 0;
}