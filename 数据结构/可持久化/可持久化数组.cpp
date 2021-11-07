#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a;i<=b;++i)
const int MAXN = 1e6+5;
inline int read() {
	int f = 1,x = 0; char ch;
	do {ch = getchar(); if (ch == '-') f = -1;} while (ch<'0' || ch>'9');
	do {x = x*10+ch-'0'; ch = getchar();} while (ch>='0' && ch<='9');
	return f * x;
}
int a[MAXN];
int tcnt,version;
struct node {
	long long v;
	node *lson, *rson;
}pool[13*MAXN],*root[MAXN*2];

void BuildTree(node *p,int left,int right) {
	if (left == right) {
		p->v = a[left];
		return;
	}
	int mid = (left+right) >> 1;
	p->lson = &pool[++tcnt];
	p->rson = &pool[++tcnt];
	BuildTree(p->lson,left,mid);
	BuildTree(p->rson,mid+1,right);
}
void change(node *last,node *p,int loc,int left,int right,long long val) {
	if (left == right) {
		p->v = val;
		return;
	}
	int mid = (left+right) >> 1;
	if (loc <= mid) {
		p->lson = &pool[++tcnt];
		p->rson = last->rson;
		change(last->lson,p->lson,loc,left,mid,val);
	}
	else {
		p->rson = &pool[++tcnt];
		p->lson = last->lson;
		change(last->rson,p->rson,loc,mid+1,right,val);
	}
}
long long query(node *p,int loc,int left,int right) {
	if (left == right) return p->v;
	int mid = (left+right) >> 1;
	if (loc <= mid) return query(p->lson,loc,left,mid);
	else return query(p->rson,loc,mid+1,right);
}
int main() {
	int n,m;
	n = read(); m = read();
	rep(i,1,n) a[i] = read();
	root[0] = &pool[++tcnt];
	BuildTree(root[0],1,n);
	rep(i,1,m) {
		int ver = read(),tt = read(),loc = read(),val;
		root[++version] = &pool[++tcnt];
		if (tt == 1) {
			val = read();
			change(root[ver],root[version],loc,1,n,val);
		}
		else {
			*root[version] = *root[ver];
			printf("%lld\n",query(root[ver],loc,1,n));
		}
	}
	return 0;
}