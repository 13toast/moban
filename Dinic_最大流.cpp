/*
poj1273
*/

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXN = 5005;
int MIN(int a,int b) {return a<b?a:b;}
int n,m,S,T;
int ccnt,lv[MAXN];
struct Edge {
	int v,f;
	Edge *next,*rev;
}*h[MAXN],*cur[MAXN],pool[10*MAXN];
queue<int> Q;
void addedge(int u,int v,int c) {
	Edge *p = &pool[++ccnt];
	Edge *q = &pool[++ccnt];
	p->v = v; p->f = c; p->next=h[u]; h[u] = p; p->rev = q;
	q->v = u; q->f = 0; q->next=h[v]; h[v] = q; q->rev = p;
}
bool makelevel() {
	mst(lv,-1);
	while (!Q.empty()) Q.pop();
	rep(i,S,T) cur[i] = h[i];
	lv[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (Edge *p=h[u];p;p=p->next) {
			int v = p->v;
			if (lv[v] == -1 && p->f) {
				Q.push(v);
				lv[v] = lv[u] + 1;
			}
		}
		if (lv[T] > 0) return true;
	}
	return false;
}
int findpath(int u,int minc) {
	if (u == T) return minc;
	int sum = 0, flow;
	for (Edge *p=cur[u];p && sum<=minc;p=p->next) {
		cur[u] = p;
		if (p->f && lv[p->v]==lv[u]+1) {
			flow = findpath(p->v,MIN(minc-sum,p->f));
			if (flow) {
				p->f -= flow;
				p->rev->f += flow;
				sum += flow;
			}
		}
	}
	if (sum == 0) lv[u] = -1;
	return sum;
}
int dinic() {
	int ret = 0;
	rep(i,S,T) cur[i] = h[i];
	while (makelevel()) {
		int tmp;
		while (tmp=findpath(S,INT_MAX)) {
			ret += tmp;
		}
	}
	return ret;
}
int main() {
	while(scanf("%d%d",&m,&n)!=EOF) {
		mst(pool,0); mst(h,0);
		for (int i=1;i<=m;i++) {
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
		    addedge(x,y,c);
		}
		S = 1; T = n;
		int ans=dinic();
		cout<<ans<<endl;
	}
} 
