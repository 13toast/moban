// luogu 4720
// n,m <= 1e18, mod <= 1e6

#include <cstdio>
using namespace std;
typedef long long ll;
inline ll fp(ll a,ll x,ll p) {
	ll ret = 1; a%=p;
	for (;x;x>>=1,a=a*a%p) if (x&1) ret=ret*a%p;
	return ret;
}
inline ll gcd(ll a,ll b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
inline void exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) {x=1,y=0; return;}
	exgcd(b,a%b,x,y);
	ll tmp = x; x = y; y = tmp-a/b*y;
}
inline ll INV(ll a,ll p) {
	ll x,y; exgcd(a,p,x,y);
	return (x+p)%p;
}
inline ll FAC(ll n,ll p,ll pk) {  // (n!/p^all) mod(p^k)
	ll ret = 1;
	for (ll x=n;x;x/=p) {
		ll t1=1, t2=1;
		for (ll i=1;i<=pk;++i) if (i%p) t1 = t1*i%pk;
		t1 = fp(t1,x/pk,pk);
		for (ll i=pk*(x/pk);i<=x;++i) if (i%p) t2 = i%pk*t2%pk;
		ret = ret*t1%pk*t2%pk;
	}
	return ret;
}
inline ll PX(ll x,ll p) {
	ll ret = 0;
	for (ll i=x;i;i/=p) ret += i/p;
	return ret;
}
inline ll C_PK(ll n,ll m,ll p,ll pk) {
	ll ret = 1;
	ret = ret * FAC(n,p,pk) * INV(FAC(m,p,pk),pk) % pk * INV(FAC(n-m,p,pk),pk) % pk;
	ret = ret * fp(p,PX(n,p)-PX(m,p)-PX(n-m,p),pk) % pk;
	return ret;
}
ll exLucas(ll n,ll m,ll mod) {
	ll md[15]={},xx[15]={},tmp=mod; int ptot=0;
	for (int i=2;i*i<=mod;++i) {
		if (tmp%i == 0) {
			ll pk = 1;
			while (tmp%i == 0) {
				tmp /= i; 
				pk *= i;
			}
			md[++ptot] = pk;
			xx[ptot] = C_PK(n,m,i,pk);
		}
	}
	if (tmp > 1) {
		md[++ptot] = tmp;
		xx[ptot] = C_PK(n,m,tmp,tmp);
	}
	//CRT
	ll ret = 0;
	for (int i=1;i<=ptot;++i) {
		ll M = mod/md[i], V = INV(M,md[i]);
		ret = (ret+xx[i]*M%mod*V%mod)%mod;
	}
	return ret;
}	

int main() {
	ll n,m,mod;
	scanf("%lld%lld%lld",&n,&m,&mod);
	printf("%lld\n",exLucas(n,m,mod));
	return 0;
}