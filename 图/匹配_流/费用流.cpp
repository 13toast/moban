#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define mst(a,b) memset(a,b,sizeof(a))
#define mcp(a,b) memcpy(a,b,sizeof(b))
using namespace std;
const int MAXN = 5005;
const int inf = 0x3f3f3f3f;
int MIN(int a,int b) {return a<b?a:b;}
int n,m,S,T,COST;
int ccnt,lv[MAXN],dis[MAXN];
bool vis[MAXN];
struct Edge {
	int v,f,co;
	Edge *next,*rev;
}*h[MAXN],*cur[MAXN],pool[20*MAXN];
queue<int> Q;
void addedge(int u,int v,int cap,int cost) {
	Edge *p = &pool[++ccnt];
	Edge *q = &pool[++ccnt];
	p->v = v; p->f = cap; p->co = cost; p->next=h[u]; h[u] = p; p->rev = q;
	q->v = u; q->f = 0; q->co = -cost; q->next=h[v]; h[v] = q; q->rev = p;
}
bool makelevel() {
	mst(dis,0x3f);
	mcp(cur,h);
	while (!Q.empty()) Q.pop();
	Q.push(S);
	dis[S] = 0;
	vis[S] = 1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		vis[u] = 0;
		for (Edge *p=h[u];p;p=p->next) {
			int v = p->v;
			if (p->f && dis[u] + p->co < dis[v]) {
				dis[v] = dis[u] + p->co;
				if(!vis[v]) {    //如果不在队列内
					Q.push(v);
 					vis[v] = true;
 				}
 			}
		}
	}
	return dis[T] != inf;
}
int findpath(int u,int minc) {
	if (u == T) return minc;
	vis[u] = 1;
	int sum = 0, flow;
	for (Edge *p=cur[u];p && sum <= minc;p=p->next) {
		cur[u] = p;
		if (p->f && !vis[p->v] && dis[p->v]==dis[u]+p->co) {
			flow = findpath(p->v,MIN(minc-sum,p->f));
			if (flow) {
				COST += flow * p->co;
				p->f -= flow;
				p->rev->f += flow;
				sum += flow;
			}
		}
	}
	vis[u] = 0;
	return sum;
}
int MCMF() {
	int ret = 0;
	while (makelevel()) {
		int tmp;
		while (tmp=findpath(S,inf)) {
			ret += tmp;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&S,&T);
	mst(pool,0); mst(h,0);
	for (int i=1;i<=m;i++) {
		int x,y,ca,co;
		scanf("%d%d%d%d",&x,&y,&ca,&co);
	    addedge(x,y,ca,co);
	}
	int ans=MCMF();
	cout<<ans<<' '<<COST<<endl;
} 
