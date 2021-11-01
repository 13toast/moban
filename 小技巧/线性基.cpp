#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105],lb[62];
inline void insert(ll x) {
	for (int i=60;i+1;--i) {
		if (!(x>>i)) continue;
		if (!lb[i]) { lb[i] = x; break; }
		x = x^lb[i];
	}
	//if (x) return false; 不能插入,表示已经能被表示
}
ll get_max() {
	ll ret = 0;
	for (int i=60;i+1;--i) 
		ret = ((ret^lb[i])>ret)?ret^lb[i]:ret;
	return ret;
}
void get_kth() { //第k小
	ll LB[62] = {};
	int cnt = 0;
	rep(i,0,60) if (lb[i]) LB[++cnt] = lb[i];
	int q; scanf("%d",&q);
	rep(i,1,q) {
		ll k,t = 0; scanf("%lld",&k);
		if (k > (1<<cnt)-1) { printf("-1\n"); continue;}
		ll ans = 0;
		while (k) {
			ans ^= (x&1)*LB[t++];
			k >>= 1;
		}
		printf("%lld\n",ans);
	} 
}
void count() {
	//如果k能用线性基表示出来,线性基能表示出这个数的方案为2^(s - tot)
	//s为线性基插入过的次数,tot为线性基的大小
}
int main() {
	int n;
	cin >> n;
	for (int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		insert(a[i]);
	}
	cout << get_max() << endl;
	get_kth();
	count_k();
	return 0;
}
