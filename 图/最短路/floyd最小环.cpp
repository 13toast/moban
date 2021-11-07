/*
必然是一个(u,v)边长+图删除(u,v)后的dis(u,v)
*/
const int N = 405;
int dis[N][N],val[N][N];
int ans = INT_MAX;
rep(i,1,n) rep(j,1,n) dis[i][j] = val[i][j];
rep(k,1,n) {
	rep(i,1,k-1) rep(j,1,i-1) ans = min(ans,dis[i][j]+val[i][k]+val[k][j]);
	rep(i,1,n) rep(j,1,n) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
}