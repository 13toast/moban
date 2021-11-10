/*
(k,w)组成，k满足二叉搜索树，w满足堆
当k互不相同，w互不相同，则笛卡尔树结构唯一
建：按k排序（一般当作下标），每次插入到右链末端
找到x.w<u.w，将u接到x右子，x原右子树变为u左子树
*/
int sta[N],top;
int ls[N],rs[N];
void build() { //O(n)
	rep(i,1,n) {
		int k = top;
		while (k > 0 && val[sta[k]] > val[i]) k--;
		if (k) rs[sta[k]] = i;	
		if (k < top) ls[i] = sta[k+1];
		sta[++k] = i;
		top = k;
	}
}