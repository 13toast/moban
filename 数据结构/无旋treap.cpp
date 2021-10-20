/*luogu 普通平衡树*/

#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;

const int MAXN = 4e5+5;

int n,m,tot;
int ch[MAXN][2],sz[MAXN];
int val[MAXN],pri[MAXN];

void clear(int x) { ch[x][0] = ch[x][1] = sz[x] = val[x] = 0; }
void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]]; }
int newnode(int v) {
	val[++tot] = v; sz[tot] = 1; pri[tot] = rand();
	return tot;
}
void split_rank(int now,int k,int &x,int &y) {
	if (!now) {
		x = 0, y = 0;
		return;
	}
	if (sz[ch[now][0]] < k) x = now, split_rank(ch[now][1],k-1-sz[ch[now][0]],ch[now][1],y);
	else y = now, split_rank(ch[now][0],k,x,ch[now][0]);
	maintain(now);
}
void split_val(int now,int k,int &x,int &y) {
	if (!now) {
		x = 0, y = 0;
		return;
	}
	if (val[now] <= k) x = now, split_val(ch[now][1],k,ch[now][1],y);
	else y = now, split_val(ch[now][0],k,x,ch[now][0]);
	maintain(now);
}
int merge(int x,int y) {
	if (!x || !y) return x+y;
	if (pri[x] < pri[y]) {
		ch[x][1] = merge(ch[x][1],y);
		maintain(x);
		return x;
	}
	else {
		ch[y][0] = merge(x,ch[y][0]);
		maintain(y);
		return y;
	}
}

int t1,t2,t3,t4,root;
void Insert(int x) {
	split_val(root,x,t1,t2);
	root = merge(merge(t1,newnode(x)),t2);
}
void Delete(int x) {
	split_val(root,x-1,t1,t2);
	split_rank(t2,1,t3,t4);
	root = merge(t1,t4);
}
int getrank(int x) {
	split_val(root,x-1,t1,t2);
	int ret = sz[t1]+1;
	root = merge(t1,t2);
	return ret;
}
int find(int x) {
	split_rank(root,x-1,t1,t2);
	split_rank(t2,1,t3,t4);
	int ret = val[t3];
	root = merge(t1,merge(t3,t4));
	return ret;
}
int main() {
	srand((unsigned)time(NULL));
	tot = 0;
	root = 0;
	int n; cin >> n;
	rep(i,1,n) {
		int type; scanf("%d",&type);
		int x; scanf("%d",&x);
		if (type == 1) Insert(x);
		if (type == 2) Delete(x);
		if (type == 3) printf("%d\n",getrank(x));
		if (type == 4) printf("%d\n",find(x));
		if (type == 5) {
			split_val(root,x-1,t1,t2);
			split_rank(t1,sz[t1]-1,t3,t4);
			printf("%d\n",val[t4]);
			root = merge(merge(t3,t4),t2);
		}
		if (type == 6) {
			split_val(root,x,t1,t2);
			split_rank(t2,1,t3,t4);
			printf("%d\n",val[t3]);
			root = merge(t1,merge(t3,t4));
		}
	}
	return 0;
}






