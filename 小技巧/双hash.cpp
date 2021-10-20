struct myhash_pair {
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1^hash2;
    }
};

unordered_map<pii,int> myhash;

pii duohash(int a[]) {
    ll h1=0,h2=0;
    rep(i,0,9) {
        h1 = (h1*31+a[i])%(1000000007);
        h2 = (h2*31+a[i])%(998244353);
    }
    return {(int)h1,(int)h2};
}

int main() {
    a[10] = {0,1,2,3,4,5,6,7,8,9,10};
    myhash[duohash(a)] = 1;
}
