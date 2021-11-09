Prufer 序列可以将一个带标号n个结点的树用[1,n]中的n-2个整数表示。完全图的生成树与数列之间的双射。

*   树建立prufer序列

    每次选择一个编号最小的叶结点并删掉它，在序列中记录下它连接到的结点，n-2次后就只剩下两个结点。

    O(n)：删除一个叶子时，判断与它相连的点标号是否小于它，如果小于，直接删除

    ```c++
    int fa[N],pru[N];
    void fa_to_pru() {
    	vector<int> deg(n+1); //后继数量
    	int ptr = -1;
    	rep(i,1,n) deg[fa[i]]++;
    	rep(i,1,n) if (deg[i] == 0) { ptr = i;break; }
    	int leaf = ptr;
    	rep(i,1,n-2) {
    		int f = fa[leaf];
    		pru[i] = f;
    		if (--deg[f] == 0 && f < ptr) leaf = f;
    		else {
    			ptr++;
    			while (deg[ptr]) ++ptr;
    			leaf = ptr;
    		}
    	}
    }
    ```

*   prufer序列建立树

    ```c++
    void pru_to_fa() {
    	vector<int> deg(n+1);
    	rep(i,1,n-2) deg[pru[i]]++;
    	int ptr = 1;
    	while (deg[ptr]) ++ptr;
    	int leaf = ptr;
    	rep(i,1,n-2) {
    		int f = pru[i]; fa[leaf] = f;
    		if (--deg[f] == 0 && f < ptr) leaf = f;
    		else {
    			++ptr;
    			while (deg[ptr]) ++ptr;
    			leaf = ptr;
    		}
    	}
    	fa[leaf] = n;
    }
    ```

*   Cayley公式

    完全图Kn有$n^{n-2}$棵生成树

*   图连通方案数

    一个n个点m条边的带标号无向图有k个连通块。添加k-1条边使得整个图连通，求方案数。

    设每一个连通块大小为$s_i$，则方案数为$n^{k-2}\prod_{i=1}^{k}s_i$

