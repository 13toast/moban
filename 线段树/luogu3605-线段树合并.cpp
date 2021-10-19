/*
luogu3605

*/

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
using namespace std;

const int N = 1e5+5;
vector<int> g[N];
int p[N],tt[N],root[N],ans[N];
int lson[20*N],rson[20*N],num[20*N];
int n,tot;
void Update(int id) {
	num[id] = num[lson[id]] + num[rson[id]];
}
void Build(int &id,int l,int r,int x) {
	id = ++tot;
	if (l == r) {
		num[id]++; return;
	}
	int mid = (l+r) >> 1;
	if (x <= mid) Build(lson[id],l,mid,x);
	else Build(rson[id],mid+1,r,x);
	Update(id);
}
int Merge(int x,int y) {
	if (!x) return y; if (!y) return x;
	lson[x] = Merge(lson[x],lson[y]);
	rson[x] = Merge(rson[x],rson[y]);
	Update(x);
	return x;
}
int Query(int id,int l,int r,int x) {
	if (!id) return 0;
	if (l >= x) return num[id];
	int mid = (l + r) >> 1;
	if (x > mid) return Query(rson[id],mid+1,r,x);
	else return Query(lson[id],l,mid,x) + Query(rson[id],mid+1,r,x);
}
void dfs(int u,int fa) {
	for (auto v:g[u]) if (v!=fa) {
		dfs(v,u);
		root[u] = Merge(root[u],root[v]);
	}
	ans[u] = Query(root[u],1,n,p[u]+1);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d",&p[i]);
		tt[i] = p[i];
	}
	sort(tt+1,tt+n+1); 
	int sz = unique(tt+1,tt+n+1)-tt-1;
	rep(i,1,n) p[i] = lower_bound(tt+1,tt+sz+1,p[i])-tt;
	rep(i,2,n) {
		int x; scanf("%d",&x);
		g[x].push_back(i); g[i].push_back(x);
	}
	rep(i,1,n) Build(root[i],1,n,p[i]);
	dfs(1,0);
	rep(i,1,n) printf("%d\n",ans[i]);
	return 0;
}