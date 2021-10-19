#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int MAXN = 5 * 1e4 + 5, MAXM = 1e5 + 5, INF = INT_MAX;
int inline swp(int& a, int& b) {
	a ^= b ^= a ^= b;
}
int inline readint() {
	int Num; char ch;
	while ((ch = getchar()) < '0' || ch > '9'); Num = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9') Num = Num * 10 + ch - '0';
	return Num;
}
void outint(int x) {
	if (x >= 10) outint(x / 10);
	putchar(x % 10 + '0');
}
struct EDGE {
	int u, v, a, b;
	bool operator < (const EDGE& _)const {
		return a < _.a;
	}
}e[MAXM];
int p[MAXN], lev[MAXN];
int inline getp(int x) {
	return x == p[x] ? x : p[x] = getp(p[x]);
}
void Union(int& x, int& y) {
	int px = getp(x), py = getp(y);
	if (lev[px] > lev[py]) p[py] = px;
	else {
		p[px] = py;
		if (lev[px] == lev[py]) lev[px]++;
	}
}
int fa[MAXN + MAXM], ch[MAXN + MAXM][2], mx[MAXN + MAXM], val[MAXN + MAXM], sta[MAXN + MAXM];
bool rev[MAXN + MAXM];
bool inline isroot(int& x) {
	return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}
void inline pushup(int& x) {
	mx[x] = x;
	if (val[mx[x]] < val[mx[ch[x][0]]]) mx[x] = mx[ch[x][0]];
	if (val[mx[x]] < val[mx[ch[x][1]]]) mx[x] = mx[ch[x][1]];
}
void inline pushdown(int& x) {
	if (rev[x]) {
		rev[x] ^= 1, rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
		swp(ch[x][0], ch[x][1]);
	}
}
void rot(int x, int p) {
	int y = fa[x], z = fa[y];
	fa[ch[x][!p]] = y, ch[y][p] = ch[x][!p];
	fa[x] = z; if (!isroot(y)) ch[z][ch[z][1] == y] = x;
	fa[y] = x, ch[x][!p] = y;
	pushup(y), pushup(x);
}
void splay(int x) {
	int top = 1; sta[top] = x;
	for (int i = x; !isroot(i); i = fa[i]) sta[++top] = fa[i];
	while (top) pushdown(sta[top--]);
	while (!isroot(x)) {
		if (isroot(fa[x])) rot(x, ch[fa[x]][1] == x);
		else {
			int y = fa[x], z = fa[y], p = ch[z][1] == y;
			if (ch[y][p] == x) rot(y, p), rot(x, p);
			else rot(x, !p), rot(x, p);
		}
	}
}
void access(int x) {
	for (int t = 0; x; t = x, x = fa[x]) {
		splay(x);
		ch[x][1] = t;
		pushup(x);
	}
}
void mkrt(int x) {
	access(x); splay(x); rev[x] ^= 1;
}
void link(int x, int y) {
	mkrt(x); fa[x] = y;
}
void cut(int x, int y) {
	mkrt(x); access(y); splay(y);
	fa[x] = ch[y][0] = 0; pushup(y);
}
int qry(int x, int y) {
	mkrt(x); access(y); splay(y);
	return mx[y];
}
int main() {
	memset(lev, 0, sizeof(lev));
	memset(rev, false, sizeof(rev));
	int n = readint(), m = readint(), ans = INF;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) e[i].u = readint(), e[i].v = readint(), e[i].a = readint(), e[i].b = readint();
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, a = e[i].a, b = e[i].b, pu = getp(u), pv = getp(v);
		if (pu == pv) {
			int t = qry(u, v);
			if (val[t] > b) cut(t, e[t - n].u), cut(t, e[t - n].v);
			else continue;
		}
		else Union(pu, pv);
		val[i + n] = b; mx[i + n] = i + n;
		link(u, i + n); link(v, i + n);
		if (getp(1) == getp(n)) ans = min(ans, a + val[qry(1, n)]);
	}
	if (ans == INF) puts("-1");
	else outint(ans);
	return 0;
}