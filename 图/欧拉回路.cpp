/*
O(N+M)
回路： 无向：度数都是偶数；有向：入度=出度
路径： 无向：0/2度数奇数； 有向：一对出=入+1 入=出+1
无向图建边正数u到v，负数v到u
*/
int n,m;
int d[N],h[N],to[M],w[M],nxt[M<<1],tot;
int ans[M],cnt;
bool vis[M<<1];
namespace UDG {
	void add(int u,int v,int l) {
		d[u]++;
		to[++tot]=v; w[tot]=l; nxt[tot]=h[u];h[u]=tot;
	}
	void dfs(int u) {
		for (int &i=h[u];i;) {
			if (vis[i]) {i=nxt[i]; continue;}
			vis[i] = vis[i^1] = 1;
			int j = w[i];
			dfs(to[i]);
			ans[++cnt] = j;
		}
	}
	void solve() {
		ed = 1;
		scanf("%d%d",&n,&m);
		rep(i,1,m) {
			int u,v; scanf("%d%d",&u,&v);
			add(u,v,i); add(v,u,-i);
		}
		rep(i,1,n) if (d[i]&1) {puts("NO"); return;}
		rep(i,1,n) if (h[i]) {dfs(i); break;}
		rep(i,1,n) if (h[i]) {puts("NO"); return;}
		puts("YES");
		per(i,m,1) printf("%d ",ans[i]);
	}
}
namespace DG {
	void add(int u,int v) {
		d[u]++; d[v]--;
		to[++tot]=v; nxt[tot]=h[u];h[u]=tot;
	}
		void dfs(int u) {
		for (int &i=h[u];i;) {
			if (vis[i]) {i=nxt[i]; continue;}
			vis[i] = 1;
			int j = i;
			dfs(to[i]);
			ans[++cnt] = j;
		}
	}
	void solve() {
		ed = 1;
		scanf("%d%d",&n,&m);
		rep(i,1,m) {
			int u,v; scanf("%d%d",&u,&v);
			add(u,v);
		}
		rep(i,1,n) if (d[i]) {puts("NO"); return;}
		rep(i,1,n) if (h[i]) {dfs(i); break;}
		rep(i,1,n) if (h[i]) {puts("NO"); return;}
		puts("YES");
		per(i,m,1) printf("%d ",ans[i]);
	}
}