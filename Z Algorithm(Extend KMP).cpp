#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int z[MAXN];
void getz(string s) {
	int len = s.length();
	int id=0,mx=0;
	z[0] = len;
	for (int i=1;i<len;++i) {
		if (mx > i) z[i] = min(z[i-id],mx-i);
		else z[i] = 0;
		for (;s[i+z[i]] == s[z[i]];++z[i]);
		if (i+z[i] > mx) {
			id = i;
			mx = i + z[i];
		}
	} 
}
void getextend(string s,string t) {

}
int main() {
	string s,t;
	cin>>s>>t;
	getz(t);
	rep(i,0,(int)t.length()-1) cout<<z[i]<<' ';
	cout<<endl;
	getextend(s,t);
}