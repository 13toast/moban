#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i) 
#define per(i,a,b) for (int i=a;i>=b;--i) 

using namespace std;
const int N = 1e5+5;

typedef long long ll;
typedef double db;

int QBS,BS,maxx;
int a[N];
struct query {
	int l,r;
	bool operator < (const query &t) const {
		if (l/QBS == t.l/QBS) {
			if ((l/QBS)&1) return r < t.r;
			else return r > t.r;
		}
		return l < t.l
	}
}q[N];
void work(int id,int w) {
	
}
int get_ans(int x) {

}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		scanf("%d",&a[i]);
		maxx = max(maxx,a[i]);
	}
	rep(i,1,m) {
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	QBS = (int)ceil(sqrt(n));
	BS  = (int)ceil(sqrt(maxx));
	sort(q+1,q+m+1);
	int l = 0,r = 0;
	rep(i,1,m) {
		query &cur = q[i];
		while (l < cur.l) work(l++,-1);
		while (l > cur.l) work(--l,1);
		while (r < cur.r) work(++r,1);
		while (r > cur.r) work(r--,-1);
		ans[cur.id] = get_ans(cur.y2)-get_ans(cur.y1-1);
	}
	rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}