//hdu 3949

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define per(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int MAXN = 1e4+5;

int n,q;
ll a[MAXN];
ll lb[62],LB[62];
inline void insert(ll x) {
	for (int i=60;i+1;--i) {
		if (!(x>>i)) continue;
		if (!lb[i]) { lb[i] = x; break; }
		x = x^lb[i];
	}
}

int main() {
	int _; cin >> _;
	while (_--) {
		memset(lb,0,sizeof(lb));
		int cnt = 0;
		scanf("%d",&n);
		rep(i,1,n) scanf("%lld",&a[i]), insert(a[i]);
		rep(i,0,60) if (lb[i]) LB[++cnt] = lb[i];
		scanf("%d",&q);
		rep(i,1,q) {
			ll x,t = 0; scanf("%lld",&x);
			if (x > (1<<cnt)-1) {
				printf("-1\n");
				continue;
			}
			ll ans = 0;
			while (x) {
				ans ^= (x&1)*LB[t++];
				x >>= 1;
			}
			printf("%lld\n",ans);
		} 
	}
	return 0;
}
