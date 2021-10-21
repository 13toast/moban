#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int inf = 2147483647;

int n,s,top;
int dis[305],fa[305];
bool vis[305];
vector<pair<int,int> > g[305];

void dfs(int u,int f) {
	fa[u] = f;
	if (dis[u] > dis[top]) top = u;
	for (auto e:g[u]) {
		int v = e.fi, w = e.se;
		if (v == f || vis[v]) continue;
		dis[v] = dis[u]+w;
		dfs(v,u);
	}
}
int main() {
	scanf("%d%d",&n,&s);
	rep(i,1,n-1) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	int p = top; top = 0;
	rep(i,0,n) dis[i] = 0,fa[i] = 0;
	dfs(p,0);
	int l = top, r = top, ans = inf;
	while (r) {
		while (dis[l]-dis[r] > s) l = fa[l];
		//cout << l << ' ' << r << endl;
		ans = min(ans,max(dis[top]-dis[l],dis[r]));
		r = fa[r];
	}
	for (int i=top;i;i=fa[i]) vis[i] = 1;
	int tmp = 0;
	for (int i=top;i;i=fa[i]) {
		top = 0;
		dfs(i,fa[i]);
		tmp = max(tmp,dis[top]-dis[i]);
	}
	printf("%d\n",max(ans,tmp));
 	return 0;
}