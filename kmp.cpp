#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+5;

string s;
int nxt[MAXN];
int main() {			//find s in t
	cin >> s;
	s += '#';
	int n = s.length();
	char ch = getchar();
	nxt[0] = 0;
	for (int i=1,j=0;i<=n;++i) {
		while (j > 0 && s[i] != s[j]) j = nxt[j-1];
		if (s[i] == s[j]) ++j;
		nxt[i] = j;
	}
	int j = 0,i = 0,cnt = 0;
	while ((ch = getchar())!='\n') {
		while (j > 0 && ch != s[j]) j = nxt[j-1];
		if (ch == s[j]) ++j;
		if (j == n-1) {
			cout << i << endl;
			cnt++; 
			j = nxt[j-1];
		}
		i++;
	}
	cout << cnt << endl;
	return 0;

}
