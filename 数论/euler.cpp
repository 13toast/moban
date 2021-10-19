#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;

int prime[MAXN],phi[MAXN],mu[MAXN],cnt;
bool vis[MAXN]; 
void euler() {
	phi[1] = 1;
	mu[1] = 1;
	for (int i=2;i<MAXN;++i) {
		if (!vis[i]) {
			mu[i] = -1;
			phi[i] = i-1;
			prime[cnt++] = i;
		}
		for (int j=0;j<cnt && 1LL*i*prime[j]<MAXN;++j) {
			vis[i*prime[j]] = 1;
			if (i % prime[j]) {
				phi[i*prime[j]] = phi[i] * (prime[j]-1);
				mu[i*prime[j]] = -mu[i];
			}
			else {
				phi[i*prime[j]] = phi[i] * prime[j];
				mu[i*prime[j]] = 0;
				break;
			}
		}
	}
}
int main() {
	euler();
	int n;
	for (int i=1;i<=cnt;++i) cout << prime[i] << endl;
	return 0;
}