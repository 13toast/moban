/*
luogu 普通平衡树
*/

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define per(i,a,b) for (int i=a;i>=b;--i)
#define mst(x,a) memset(x,a,sizeof(x))
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 1e5+5;

int MAX(int a,int b) {return a>b?a:b;}
int MIN(int a,int b) {return a<b?a:b;}

int val[MAXN]; //编号i的值
int num[MAXN]; //值为val[i]的有num[i]个
int ch[MAXN][2],fa[MAXN],sz[MAXN];
int ROOT,tot;

void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = sz[x] = val[x] = num[x] = 0; }
bool which(int x) { return x == ch[fa[x]][1]; }
void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + num[x]; }
void rotate(int x) {
	int p = fa[x], gp = fa[p], wc=which(x);
	ch[p][wc] = ch[x][wc^1]; fa[ch[x][wc^1]] = p;
	ch[x][wc^1] = p; fa[p] = x;
	fa[x] = gp; if (gp) ch[gp][p == ch[gp][1]] = x;
	maintain(x);maintain(p);
}
void splay(int x) {
	for (int p;p=fa[x];rotate(x)) 
		if (fa[p]) rotate((which(x) == which(p)?p:x));
	ROOT = x;
}
int getrank(int k) {
	int now = ROOT, ret = 0;
	while (true) {
		if (k < val[now]) now = ch[now][0];
		else {
			ret += sz[ch[now][0]];
			if (k == val[now]) {
				splay(now);
				return ret+1;
			}
			ret += num[now];
			now = ch[now][1];
		}
	}
}
int find(int k) {
	int now = ROOT;
	while (true) {
		if (ch[now][0] && k <= sz[ch[now][0]]) now = ch[now][0];
		else {
			k -= sz[ch[now][0]]+num[now];
			if (k <= 0) {
				splay(now);
				return val[now];
			}
			now = ch[now][1];
		}
	}
}
int prenxt(bool t) { // 0 pre,  1 nxt
	int now = ch[ROOT][t];
	while (ch[now][t^1]) now = ch[now][t^1];
	splay(now);
	return now;
}
void newnode(int v,int p) {
	val[++tot] = v; num[tot]++;
	maintain(tot);
	if (p) {
		fa[tot] = p;
		ch[p][v > val[p]] = tot;
		maintain(p);
	}
}
void Insert(int v) {
	if (!ROOT) {
		newnode(v,0);
		ROOT = tot;
		return;
	}
	int now = ROOT,p = 0;
	while (true) {
		if (val[now] == v) {
			num[now]++;
			maintain(now); maintain(p);
			splay(now);
			break;
		}
		p = now;
		now = ch[now][v > val[now]];
		if (!now) {
			newnode(v,p);
			splay(tot);
			break;
		}
	}
}
void Delete(int x) {  //删除值为x的
	getrank(x);
	if (num[ROOT] > 1) {
		num[ROOT]--;
		maintain(ROOT);
		return;
	}
	if (!ch[ROOT][0] && !ch[ROOT][1]) { clear(ROOT); ROOT = 0; return; }
	rep(i,0,1) if (!ch[ROOT][i]) {
		int tmp = ROOT;
		ROOT = ch[ROOT][i^1]; fa[ROOT] = 0;
		clear(tmp);
		return;
	}
	int now = ROOT, pre=prenxt(0); //pre时splay过，用now存之前的root
	fa[ch[now][1]] = pre;
	ch[pre][1] = ch[now][1];
	clear(now);
	maintain(ROOT);
}
int main() {
	tot = 0;
	int n; cin >> n;
	rep(i,1,n) {
		int type; scanf("%d",&type);
		int x; scanf("%d",&x);
		if (type == 1) Insert(x);
		if (type == 2) Delete(x);
		if (type == 3) printf("%d\n",getrank(x));
		if (type == 4) printf("%d\n",find(x));
		if (type == 5) {
			Insert(x);
			printf("%d\n",val[prenxt(0)]);
			Delete(x);
		}
		if (type == 6) {
			Insert(x);
			printf("%d\n",val[prenxt(1)]);
			Delete(x);
		}
	}
	return 0;
}


