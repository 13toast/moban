#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000
using namespace std;
int n,m=200,c[N],x[N],y[N],sa[N];
char s[N];
void build_sa() {
	for (int i=0;i<m;i++)	 c[i]=0;
	for (int i=0;i<n;i++)	 c[x[i]=s[i]]++;
	for (int i=1;i<m;i++)	 c[i]+=c[i-1];
	for (int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;

	for (int k=1;k<=n;k<<=1)
	{
		int p=0;
		for (int i=n-k;i<n;i++)	 y[p++]=i;
		for (int i=0;i<n;i++)	 if (sa[i]>=k) y[p++]=sa[i]-k;
		for (int i=0;i<m;i++)	 c[i]=0;
		for (int i=0;i<n;i++)	 c[x[i]]++;
		for (int i=1;i<m;i++)	 c[i]+=c[i-1];
		for (int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1; x[sa[0]]=0;
		for (int i=1;i<n;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&((sa[i-1]+k>=n?-1:y[sa[i-1]+k])==(sa[i]+k>=n?-1:y[sa[i]+k]))?p-1:p++;
		if (p>n) break;
		m=p;
	}	
}
int rk[N],height[N];
void build_height() {
	for (int i=0;i<n;++i) rk[sa[i]]=i;
	int k=0; 
	height[0] = 0;
	for (int i=0;i<n;++i)
	{
		if (!rk[i]) continue;
		if (k) --k;
		int j=sa[rk[i]-1];
		while (i+k<n&&j+k<n&&s[i+k]==s[j+k]) ++k;
		height[rk[i]]=k;
	}
}
int main() {
	scanf("%s",s);
	n = strlen(s);
	build_sa();
	build_height();
	
	return 0;
}