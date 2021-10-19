#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
using namespace std;

const int N = 1e5+5;
const int NN = 20*3*N;

int n,m,tot,sz,q;
int num[NN],lson[NN],rson[NN];
int p[N],fa[N],root[N];
void Update(int id) { num[id] = num[lson[id]] + num[rson[id]]; }
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
int Find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x,int y) {
	x = Find(x); y = Find(y);
	if (x != y) {
		fa[y] = x;
		root[x] = Merge(x,y);
	}
}
int Query(int id,int l,int r,int k) {
	if (!id) return -1;
	if (l == r) {
		if (num[id] >= k) return l;
		return -1;
	}
	int mid = (l + r) >> 1;
	if (k > num[mid]) return Query(rson[id],mid+1,r,k-num[lson[id]]);
	return Query(lson[id],l,mid,k);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&p[i]),sz = max(sz,p[i]),fa[i] = i;
	rep(i,1,n) Build(root[i],1,sz,p[i]);
	rep(i,1,m) {
		int x,y; scanf("%d%d",&x,&y);
		Union(x,y);
	}
	scanf("%d",&q);
	rep(i,1,q) {
		int x,y; char ch[1]; scanf("%s%d%d",ch,&x,&y);
		if (ch[0] == 'Q') printf("%d\n",Query(root[Find(x)],1,sz,y));
		else Union(x,y);
	}
	return 0;
}