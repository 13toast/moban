/*
处理树上询问点数和n在同一个量级，每一个询问约等于一个树dp
*/
#include <bits/stdc++.h> 
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define per(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n,m,k;
int h[N],mk[N]; //mk标记关键点
ll dp[N];
struct edge {
	int v,w;
};
vector<edge> g[N],vt[N];
int idx,id[N],fa[N][20],dep[N];
int me[N][20]; //向上最短边
void dfs(int u,int f) {
	id[u] = ++idx;
	dep[u] = dep[f]+1; fa[u][0] = f;
	for (auto e:g[u]) {
		int v = e.v,w = e.w;
		if (v == f) continue;
		dfs(v,u);
		me[v][0] = w;
	}
}
int lca(int a,int b) {
	if (dep[a] < dep[b]) swap(a,b);
	int dis = dep[a] - dep[b];
	per(i,18,0) if (dis>>i&1) a = fa[a][i];
	if (a == b) return a;
	per(i,18,0) if (fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int sta[N],top;
inline bool cmp(int a,int b) { return id[a] < id[b]; }
inline int getme(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	if (u == v) return 0;
	int ret = INT_MAX;
	int cur = u;
	per(i,18,0) if (dep[fa[cur][i]] <= v) {
		ret = min(ret,me[cur][i]);
		cur = fa[cur][i];
	}
	return ret;
}
inline void add(int u,int v) {
	int w = getme(u,v);
	vt[u].push_back((edge){v,w});
	vt[v].push_back((edge){u,w});
}
void build() {
	sort(h+1,h+k+1,cmp);
	sta[top=1] = 1; vt[1].clear();
	rep(i,1,k) {
		if (h[i] == 1) continue;
		int l = lca(h[i],sta[top]);
		if (l != sta[top]) {
			while (id[l] < id[sta[top-1]])
				add(sta[top-1],sta[top]), top--;
			if (id[l] > id[sta[top-1]])
				vt[l].clear(),add(l,sta[top]),sta[top] = l;
			else add(l,sta[top--]);
		}
		vt[h[i]].clear();
		sta[++top] = h[i];
	}
	rep(i,1,top-1) add(sta[i],sta[i+1]);
}
void solve(int u,int f) {
	dp[u] = 0;
	for (auto e:vt[u]) {
		int v = e.v,w = e.w;
		if (v == f) continue;
		solve(v,u);
		if (mk[v]) dp[u] += (ll)w;
		else dp[u] += min(dp[v],(ll)w);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,18) me[i][j] = INT_MAX;
	rep(i,1,n-1) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back((edge){v,w});
		g[v].push_back((edge){u,w});
	}
	dfs(1,0);
	rep(i,1,18) rep(j,1,n) {
		fa[j][i] = fa[fa[j][i-1]][i-1];
		me[j][i] = min(me[fa[j][i-1]][i-1],me[j][i-1]);
	}
	scanf("%d",&m);
	rep(i,1,m) {
		scanf("%d",&k);
		rep(i,1,k) scanf("%d",&h[i]),mk[h[i]] = 1;
		build();
		solve(1,0);
		printf("%lld\n",dp[1]);
		rep(i,1,k) mk[h[i]] = 0;
	}
}