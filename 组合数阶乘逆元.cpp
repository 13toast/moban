ll fac[N],invf[N];
ll fp(ll a, ll x) {
    ll ret = 1;
    for (;x;x>>=1,a=a*a%mod) if (x&1) ret=ret*a%mod;
    return ret;
}
ll C(ll a, ll b) {
    if (b == 0) return 1;
    return fac[a]*invf[b]%mod*invf[a-b]%mod;
}
void init() {
    fac[1] = 1;
    rep(i,2,2e5) fac[i] = fac[i-1]*i%mod;
    invf[200000] = fp(fac[200000],mod-2);
    per(i,199999,0) invf[i] = invf[i+1]*(i+1)%mod;
}