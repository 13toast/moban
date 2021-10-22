#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define per(i,a,b) for (int i=a;i>=b;--i)
#define mst(a,b) memset(a,b,sizeof(a))

typedef long long ll;
typedef double db;

using namespace std;

const int MAXN = 1e5+5;

int n,m;
ll a[MAXN];
struct segment_tree {
	#define ls id<<1
	#define rs id<<1|1
	struct node {
		ll sum, lazy;
	}tr[4*MAXN];

	void Update(int id) {
		tr[id].sum = tr[ls].sum + tr[rs].sum;
	}
	void pushdown(int id,int l,int r) {
		int mid = (l+r)/2;
		if (tr[id].lazy) {
			tr[ls].sum += tr[id].lazy*(mid-l+1); tr[ls].lazy += tr[id].lazy;
			tr[rs].sum += tr[id].lazy*(r-mid);   tr[rs].lazy += tr[id].lazy;
			tr[id].lazy = 0;
		}
	}
	void BuildTree(int id,int l,int r) {
		tr[id].lazy = 0;
		if (l == r) {
			tr[id].sum = a[l];
			return;
		}
		int mid = (l+r) >> 1;
		BuildTree(ls,l,mid); BuildTree(rs,mid+1,r);
		Update(id);
	}
	void Change(int id,int l,int r,int cl,int cr,int k) {
		if (cl <= l && r <= cr) {
			tr[id].lazy += k;
			tr[id].sum += (r-l+1)*k;
			return;
		}
		pushdown(id,l,r);
		int mid = (l+r) >> 1;
		if (cl <= mid) Change(ls,l,mid,cl,cr,k);
		if (cr > mid)  Change(rs,mid+1,r,cl,cr,k);
		Update(id);
	}
	ll Query(int id,int l,int r,int ql,int qr) {
		if (ql <= l && r <= qr) {
			return tr[id].sum;
		}
		pushdown(id,l,r);
		int mid = (l+r) >> 1;
		ll ret = 0;
		if (ql <= mid) ret += Query(ls,l,mid,ql,qr);
		if (qr > mid)  ret += Query(rs,mid+1,r,ql,qr);
		return ret;
	}	
	#undef ls
	#undef rs
}sgt;
int main() {
	cin >> n >> m;
	rep(i,1,n) scanf("%lld",&a[i]);
	sgt.BuildTree(1,1,n);
	rep(i,1,m) {
		int ty; scanf("%d",&ty);
		int x,y;ll k;
		if (ty == 1) {
			scanf("%d%d%lld",&x,&y,&k);
			sgt.Change(1,1,n,x,y,k);
		}
		else {
			scanf("%d%d",&x,&y);
			printf("%lld\n",sgt.Query(1,1,n,x,y));
		}
	}
	return 0;
}