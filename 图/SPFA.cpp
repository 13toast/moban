#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 100010;
const ll INF = 0x7fffffff;
const double eps = 1e-8;
const int mod = 1e7+7;

vector<pii> vec[MAXN];
queue<pii> Q;

int dis[MAXN], cnt[MAXN]; //cnt记录每个点入队次数,==n说明有负环
bool vis[MAXN];			  //是否进队
int n, m, S;

bool SPFA() {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	Q.push(make_pair(0, S));
	dis[S] = 0;
	cnt[S]++;
	while (!Q.empty()) {
		int u = Q.front().second;
		Q.pop();
		vis[u] = 0;
		for (int i=0;i<(int)vec[u].size();++i) {
			int v = vec[u][i].second, w = vec[u][i].first;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				cnt[v]++;
				if (cnt[v] >= n) return true;
				if(!vis[v]) {    //如果不在队列内
					Q.push(make_pair(dis[v], v));
 					vis[v] = true;
 				}
 			}

		}
	}
	return false;
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