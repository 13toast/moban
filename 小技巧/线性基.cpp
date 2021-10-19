#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];

ll lb[62];
inline void insert(ll x) {
	for (int i=60;i+1;--i) {
		if (!(x>>i)) continue;
		if (!lb[i]) { lb[i] = x; break; }
		x = x^lb[i];
	}
}
ll get_max() {
	ll ret = 0;
	for (int i=60;i+1;--i) 
		ret = ((ret^lb[i])>ret)?ret^lb[i]:ret;
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		insert(a[i]);
	}
	cout << get_max() << endl;
	return 0;
}
