#include <bits/stdc++.h>
using namespace std;
int a,b,x,p;
typedef long long ll;
unordered_map<ll,int> myhash;
ll quick_pow(ll a,ll x,ll p) {
	ll ret = 1;
	for (ll i=a;x;x>>=1,i=(i*i)%p) if (x&1) ret = (ret*i)%p;
	return ret%p;
}
ll BSGS(ll a,ll b,ll c) { //pow(a,x)==b (%c) (a,c)==1 
	myhash.clear();
	int sqc = sqrt(c),j;
	ll tmp = a*b%c;
	for (int i=1;i<=sqc;++i) {
		myhash.insert({tmp,i});
		tmp = (tmp*a)%c;
	}
	ll aqp = quick_pow(a,sqc,c);
	tmp = aqp;
	for (int i=1;i<=sqc;++i) {
		if (j=myhash[tmp]) return i*sqc-j;
		tmp = (tmp*aqp)%c;
	}
	return -1;
}
int main() {
	ll a,b,c;
	cin >> c >> a >> b;
	ll ans = BSGS(a,b,c);
	if (ans == -1) cout << "no solution" << endl;
	else cout << ans << endl;
	return 0;
}