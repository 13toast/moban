typedef long long ll;
inline ll mul(ll a,ll b,const ll &p) {
	ll lf = a*(b>>25LL)%p * (1LL<<25)%p;
	ll rg = a*(b & ((1LL<<25)-1))%p;
	return (lf+rg)%p;
}
