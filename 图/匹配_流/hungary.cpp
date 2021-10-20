#include <bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define pb push_back
const int MAXN = 1005;
int n,m;
vector<int> vec[MAXN];
bool used[MAXN];
int pa[MAXN];
bool Hungary(int x) {
	rep(i,0,(int)vec[x].size()-1) {
		int v = vec[x][i];
		if (!used[v]) {
			used[v] = 1;
			if (pa[v] == 0 || Hungary(pa[v])) {
				pa[v] = x;
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin>>n>>m;
	mst(pa,0); mst(used,0);
	rep(i,1,m) {
		int a,b; cin>>a>>b;
		vec[a].pb(b);
	}
	int ans = 0;
	rep(i,1,n) {
		mst(used,0);
		if (Hungary(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}