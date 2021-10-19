#include <bits/stdc++.h>
#include <complex>
using namespace std;
#define rep(i,a,b) for (int i=a;i<=b;++i) 
#define mst(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef double db;
typedef complex<double> COMP;
const db eps = 1e-8;
const db PI = 3.141592653589793;
const int MAXN = 1<<15;
struct FastFourierTransform {
	void transform(COMP *a,int n,int dir) {
		int k = 0; 
		while ((1<<k) < n) ++k;
		rep(i,0,n-1) {
			int rev = 0;
			rep(j,0,k-1) if (i & (1<<j)) rev |= (1 << (k-j-1));
			if (i < rev) swap(a[i],a[rev]);
		}
		for (int l=2;l<=n;l<<=1) {
			COMP om(cos(2*PI/l),sin(dir*2*PI/l));
			for (int j=0;j<n;j+=l) {
				COMP om1(1,0);
				for (int k=j;k<j+l/2;++k) {
					COMP p = a[k];
					COMP q = om1 * a[k+l/2];
					a[k] = p + q;
					a[k+l/2] = p - q;
					om1 *= om;
				}
			}
		}
		if (dir == -1) {
			rep(i,0,n) a[i] /= n;
		}
		return;
	}

	void work(int *a,int n1,int *b,int n2,int *res) {
		int N = 1;
		while (N < n1+n2) N <<= 1;
		COMP c1[MAXN],c2[MAXN];
		rep(i,0,n1-1) c1[i].real(a[i]);
		rep(i,0,n2-1) c2[i].real(b[i]);
		transform(c1,N,1);
		transform(c2,N,1);
		rep(i,0,N-1) c1[i] *= c2[i];
		transform(c1,N,-1);
		rep(i,0,n1+n2-2) res[i] = static_cast<int>(floor(c1[i].real()+0.50));
		return;
	}
}FFT;

int main() {
	
	
	return 0;
}