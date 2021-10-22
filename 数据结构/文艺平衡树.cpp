/*
luogu 文艺平衡树
*/

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define per(i,a,b) for (int i=a;i>=b;--i)
#define mst(x,a) memset(x,a,sizeof(x))
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 1e5+5;
const int inf = 1e9;

int MAX(int a,int b) {return a>b?a:b;}
int MIN(int a,int b) {return a<b?a:b;}

int n,m; 
int val[MAXN],num[MAXN];
int ch[MAXN][2],fa[MAXN],sz[MAXN];
bool tag[MAXN];
int ROOT,tot;

void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = sz[x] = val[x] = num[x] = tag[x] = 0; }
bool which(int x) { return x == ch[fa[x]][1]; }
void maintain(int x) { 
	if (!x) return;
	sz[x] = num[x];
	if (ch[x][0]) sz[x] += sz[ch[x][0]];
	if (ch[x][1]) sz[x] += sz[ch[x][1]];
}
void pushdown(int x) {
	if (tag[x]) {
		if (ch[x][0]) tag[ch[x][0]] ^= 1;
		if (ch[x][1]) tag[ch[x][1]] ^= 1;
		swap(ch[x][0],ch[x][1]);
		tag[x] = 0;
	}
}
int BuildTree(int p, int l, int r) {
	if (l > r) return 0;
	int now = ++tot;
	int mid = (l+r)/2;
	clear(now);
	fa[now] = p;
	val[now] = mid-1;
	if (mid == 1) val[now] = -inf;
	if (mid == n+2) val[now] = inf;
	num[now] = 1;
	ch[now][0] = BuildTree(now,l,mid-1);
	ch[now][1] = BuildTree(now,mid+1,r);
	maintain(now);
	return now;
}
void rotate(int x) {
	int p = fa[x], gp = fa[p];
	pushdown(p); pushdown(x);
	int wc=which(x);
	ch[p][wc] = ch[x][wc^1]; fa[ch[x][wc^1]] = p;
	ch[x][wc^1] = p; fa[p] = x;
	fa[x] = gp; if (gp) ch[gp][p == ch[gp][1]] = x;
	maintain(x);maintain(p);
}
void splay(int x,int to) {
	for (int p;(p=fa[x]) && fa[x]!=to;rotate(x)) 
		if (fa[p] != to) rotate((which(x) == which(p)?p:x));
	if (to == 0) ROOT = x;
}
int find(int k) {
	int now = ROOT;
	while (true) {
		pushdown(now);
		if (k <= sz[ch[now][0]]) now = ch[now][0];
		else if (k == sz[ch[now][0]]+1) return now;
		else {
			k -= sz[ch[now][0]]+1;
			now = ch[now][1];
		}
	}
}
void reverse(int l,int r) {
    l = find(l-1);
    r = find(r+1);
    splay(l,0); splay(r,l);
    tag[ch[ch[ROOT][1]][0]] ^= 1;
}
void output(int x) {
	pushdown(x);
	if (ch[x][0]) output(ch[x][0]);
	if (val[x]!=inf && val[x]!=-inf) cout<<val[x]<<' ';
	if (ch[x][1]) output(ch[x][1]);
}
int main() {
	tot = 0;
	cin >> n >> m;
	ROOT = BuildTree(0,1,n+2);
	rep(i,1,m) {
		int x, y; 
		cin >> x >> y;
		reverse(x+1,y+1);
	}
	output(ROOT);
	cout<<endl;
	return 0;
}


