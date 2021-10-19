#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mst(x) memset(x,0,sizeof(x))
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
	int cnt = 0;
	vector<pii> a;
	for (int i=5;i>=1;i--) {
		for (int j=5;j>=1;j--) {
			a.pb(mp(i,j));
		}
	}
	sort(a.begin(),a.end());
	for (int i=1;i<a.size();i++) cout<<a[i].first<<' '<<a[i].second<<endl;
	return 0;
}