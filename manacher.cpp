#include <bits/stdc++.h>
#define RUSH ios_base::sync_with_stdio(0)
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXN = 3334;
int MIN(int a,int b) {return a<b?a:b;}
int MAX(int a,int b) {return a>b?a:b;}
int n,m;
int len;
int p[MAXN],mapp[2][MAXN][MAXN];
char a[MAXN],str[MAXN],mater[MAXN][MAXN];
void manacher() { //p是半径，扩倍以后相当于原串直径
	len = strlen(str);

	int id,mx = 0;
	rep(i,1,len-1) {
		if (mx > i) p[i] = MIN(p[2*id-i],mx-i);
		else p[i] = 1;
		for (;str[i+p[i]]==str[i-p[i]];p[i]++);
		if (p[i]+i > mx) {
			mx = p[i] + i;
			id = i;
		}
	}
}
void work(char a[],int num,int t) {
	mst(str,0);
	str[0] = '$'; str[1] = '#';
	for (int i=0;a[i];++i) {
		str[2*i+2] = a[i];
		str[2*i+3] = '#';
	}
	len = strlen(str);
	str[len] = '*';
	manacher();
	int cnt = 0;
	rep(i,1,len-1) {
		if (str[i]>='a'&&str[i]<='z') mapp[t][num][++cnt] = p[i]-1;
	}
}
void init() {
	int m,n;
	scanf("%d%d",&m,&n);
	rep(i,0,m-1) scanf("%s",mater[i]);
	rep(i,0,m-1) {
		rep(j,0,n-1) a[j] = mater[i][j];
		work(a,i+1,0);
	}
	rep(i,0,n-1) {
		rep(j,0,m-1) a[j] = mater[j][i];
		work(a,i+1,1);
	}
	int ans = 0;
	rep(i,1,m) rep(j,1,n) ans = MAX(ans,mapp[0][i][j]*mapp[1][i][j]);
	cout<<ans<<endl;
}
int main() {
	init();
}
