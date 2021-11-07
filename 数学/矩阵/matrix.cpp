#include <bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a));
const int MAXN = 100;

struct Matrix {
	int r,c;
	int mat[MAXN][MAXN];
	void clear(int x, int y) {
		r = x;
		c = y;
		mst(mat,0);
	}
	void ini() {
		for (int i=0;i<r;i++) mat[i][i] = 1;
	}
	Matrix operator +(const Matrix &b) const {
		Matrix tmp;
		tmp.r = r; tmp.c = c;
		for (int i=0;i<r;++i) 
			for (int j=0;j<c;++j) 
				tmp.mat[i][j]=(mat[i][j]+b.mat[i][j])%mod;
		return tmp;
	}
	Matrix operator *(const Matrix &b) const {
		Matrix tmp;
		tmp.clear(r,b.c);
		for (int i=0;i<r;++i) 
			for (int j=0;j<b.c;++j) 
				for (int k=0;k<c;++k)
					tmp.mat[i][j] = (tmp.mat[i][j]+(mat[i][k]*b.mat[k][j])%mod)%mod;
		return tmp;
	}
};
int main() {
	return 0;
}