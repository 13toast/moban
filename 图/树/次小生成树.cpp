const int MAXN=110;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int Max[MAXN][MAXN]; // longest edge from i to j on mst
bool used[MAXN][MAXN];
int Prim(int n)
{
	int ans=0;
	memset(vis,false,sizeof(vis));
	memset(Max,0,sizeof(Max));
	memset(used,false,sizeof(used));
	vis[0]=true;
	pre[0]=-1;
	for(int i=1;i<n;i++)
	{
		lowc[i]=cost[0][i];
		pre[i]=0;
	}
	lowc[0]=0;
	for(int i=1;i<n;i++)
	{
		int minc=INF;
		int p=-1;
		for(int j=0;j<n;j++)
		if(!vis[j]&&minc>lowc[j])
		{
			minc=lowc[j];
			p=j;
		}
		if(minc==INF)return -1;
		ans+=minc;
		vis[p]=true;
		used[p][pre[p]]=used[pre[p]][p]=true;
		for(int j=0;j<n;j++)
		{
			if(vis[j]&&j!=p)Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
			if(!vis[j]&&lowc[j]>cost[p][j])
			{
				lowc[j]=cost[p][j];
				pre[j]=p;
			}
		}
	}
	return ans;
}
int smst(int n,int ans) //point id start from 0
{
    int Min=INF;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(cost[i][j]!=INF && !used[i][j])
            {
                Min=min(Min,ans+cost[i][j]-Max[i][j]);
            }
    if(Min==INF)return -1;// no
    return Min;
}
