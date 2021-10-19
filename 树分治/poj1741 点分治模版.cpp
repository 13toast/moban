#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define mst(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
int MAX(int a,int b) { return a>b?a:b; }
const int MAXN = 1e5+5;
const int inf = 2147483647;

vector<pii> vec[MAXN];
int n,m,G = 1,tot,ans;
int sz[MAXN],mxson[MAXN],dis[MAXN];
bool vis[MAXN];
void getG(int u,int fa) {
	sz[u] = 1;
	mxson[u] = 0;
	rep(i,0,(int)vec[u].size()-1) {
		int v = vec[u][i].fi;
		if (!vis[v] && v!=fa) {
			getG(v,u);
			sz[u] += sz[v];
			mxson[u] = MAX(mxson[u],sz[v]);
		}
	}
	mxson[u] = MAX(mxson[u],tot - sz[u]);
	G = mxson[G] > mxson[u]?u:G;
}
int dcnt = 0;
void getdis(int u,int fa,int dep) {
	dis[++dcnt] = dep;
	rep (i,0,(int)vec[u].size()-1) {
		int v = vec[u][i].fi;
		if (v != fa && !vis[v]) getdis(v,u,dep+vec[u][i].se);
	}
}
int calc(int u,int add) {
	int ret = 0;
	dcnt = 0;
	getdis(u,0,add);
	sort(dis+1,dis+dcnt+1);
	for (int l = 1,r = dcnt;l < r;) {
		if (dis[l] + dis[r] > m) r--;
		else {
			ret += r-l;
			l++;
		}
	}
	return ret;
}
void divide(int u) {
	vis[u] = 1;
	ans += calc(u,0);
	rep(i,0,(int)vec[u].size()-1) {
		int v = vec[u][i].fi;
		if (!vis[v]) {
			ans -= calc(v,vec[u][i].se); //减去两点在同一棵子树的情况
			G = 0; mxson[G] = inf; tot = sz[v];
			getG(v,u);
			divide(G);
		}
	}
}
int main() {
	while (scanf("%d%d",&n,&m)) {
		if (n == 0 && m == 0) break;
		rep(i,1,n) vec[i].clear();
		mst(vis,0);
		ans = 0;
		rep(i,1,n-1) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			vec[x].pb(mp(y,z)); vec[y].pb(mp(x,z));
		}
		G = 0; mxson[G] = inf; tot = n;
		getG(1,0);
		divide(G);
		cout<<ans<<endl;
	}
	return 0;	
}