/*
O(mlogm)
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 100010;
const ll INF = 0x7fffffff;
const double eps = 1e-8;
const int mod = 1e7+7;

vector<pii> vec[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int dis[MAXN];
bool vis[MAXN];
int n, m, S;

void dijk() {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.push(make_pair(0, S));
	dis[S] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i=0;i<vec[u].size();++i) {
			int v = vec[u][i].second, w = vec[u][i].first;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push(make_pair(dis[v], v));
 			}

		}
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i=1;i<=m;++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vec[u].push_back(make_pair(w, v));
		vec[v].push_back(make_pair(w, u));
	}
	dijk();
	int ans = INT_MAX;
	for (int i=1;i<=n;i++) ans = min(ans, dis[i]);
	printf("%d\n",ans);
	return 0;
}
