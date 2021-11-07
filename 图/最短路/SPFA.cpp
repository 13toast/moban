#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 100010;
const ll INF = 0x7fffffff;
const double eps = 1e-8;
const int mod = 1e7+7;

vector<pii> vec[MAXN];
queue<pii> Q;

int dis[MAXN], cnt[MAXN]; //cnt记录每个点入队次数,>=n说明有负环
bool vis[MAXN];			  //是否进队
int n, m, S;

struct edge {
  int v, w;
};
bool SPFA() {

vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
        if (cnt[v] >= n) return false;
        // 在不经过负环的情况下，最短路至多经过 n - 1 条边
        // 因此如果经过了多于 n 条边，一定说明经过了负环
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return true;
}
}
int main() {
	scanf("%d%d%d", &n, &m,&S);
	for (int i=1;i<=m;++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vec[u].push_back(make_pair(w, v));
		//vec[v].push_back(make_pair(w, u));
	}
	bool a=SPFA();
	if (a == 1) cout<<"!!!!"<<endl;
	else  {
		for (int i=1;i<=n;i++) cout<<dis[i]<<' ';
	cout<<endl;
	}
	
	//printf("%d\n",ans);
	return 0;
}