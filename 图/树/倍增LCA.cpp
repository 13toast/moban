#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
const int MAXN = 100010;
struct node {
	int v;
};
vector<node> tr[MAXN];
int pnt[MAXN][20],dep[MAXN],root,n;
bool vis[MAXN];
int findroot(int u) {
	if (pnt[u][0]) return findroot(pnt[u][u]);
	return u;
}
void addedge(int u,int v) {
	node tmp; tmp.v=v;
	tr[u].pb(tmp);
	pnt[v][0] = u;
}
void dfs(int u) {
	vis[u] = 1;
	for (int i=0;i<tr[u].size();i++) {
		int v = tr[u][i].v;
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
	return;
}
int lca(int a, int b) {
	if (dep[a]<dep[b]) swap(a,b);
	int dis = dep[a] - dep[b];
	for (int i=16;i>=0;i--) 
		if ((1<<i)&dis) a = pnt[a][i];
	if (a == b) return a;
	for (int i=16;i>=0;i--) {
		if (pnt[a][i] != pnt[b][i]) a=pnt[a][i],b=pnt[b][i];
	}
	return pnt[a][0];
}
int main() {
	mst(pnt,0); mst(vis,0); mst(dep,0);
	root = findroot(1);
	dep[root] = 1;
	dfs(root);
	for (int i=1;i<=16;i++) 
		for (int j=1;j<=n;j++)
			pnt[j][i] = pnt[pnt[j][i-1]][i-1];
	int a,b,c;
	c = lca(a,b);
	return 0;
}