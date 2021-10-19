//luogu ac自动机简单版模版

#include <bits/stdc++.h>
#define RUSH ios_base::sync_with_stdio(0)
using namespace std;
const int MAXN = 1000010;

int n,tcnt;
struct Ahoy {
	int c[30];
	int fail;
	int end;
}tr[MAXN];
void Insert(string s) {
	int now = 0;
	int len = s.length();
	for (int i=0;i<len;i++) {
		int ch = s[i]-'a'+1;
		if (!tr[now].c[ch]) tr[now].c[ch] = ++tcnt;
		now = tr[now].c[ch];
	}
	tr[now].end++;
}
void getfail() {
	queue<int> Q;
	for (int i=1;i<=26;i++) {
		if (tr[0].c[i]) {
			tr[tr[0].c[i]].fail = 0;
			Q.push(tr[0].c[i]);
		}
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i=1;i<=26;i++) {
			if (tr[now].c[i]) {
				tr[tr[now].c[i]].fail = tr[tr[now].fail].c[i];
				Q.push(tr[now].c[i]);
			}
			else tr[now].c[i] = tr[tr[now].fail].c[i]; //字典图
		}
	}
}
int Query(string s) {
	int len = s.length();
	int now = 0, ans = 0;
	for (int i=0;i<len;i++) {
		int ch = s[i]-'a'+1;
		now = tr[now].c[ch];
		for (int j=now;j&&tr[j].end!=-1;j=tr[j].fail) {
			ans += tr[j].end;
			tr[j].end = -1;
		}
	}
	return ans;
}
int main() {
	RUSH;
	cin>>n;
	for (int i=1;i<=n;i++) {
		string s;
		cin>>s;
		Insert(s);
	}
	tr[0].fail = 0;
	getfail();
	string m;
	cin>>m;
	cout<<Query(m)<<endl;
	return 0;
}