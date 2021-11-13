#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for (int a=b;a<=c;++a)
#define pb push_back
const int MAXN = 10001;
int n,m,belong[MAXN],dfn[MAXN],low[MAXN],INDEX,bcnt;
bool in[MAXN];
vector<int> vec[MAXN];
stack<int> st;
int MIN(int a,int b) {return a>b?b:a;}
void tarjan_SCC(int u)
{
    int v;
    dfn[u] = low[u] = ++INDEX;
    st.push(u);
    in[u] = true;
    rep(i,0,(int)vec[u].size()-1) {
        v = vec[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = MIN(low[u],low[v]);
        }
        else if(in[v]) {
            low[u] = MIN(low[u],dfn[v]);
        }
    }
    v= -1;
    if(dfn[u] == low[u]) {
        bcnt++;
        do {
            v = st.top(); st.pop();
            belong[v] = bcnt;
            in[v] = false;
        } while(v != u);
    }
}
void tarjan_EDGE(int u,int fa) {
    int v;
    dfn[u] = low[u] = ++INDEX;
    rep(i,0,(int)vec[u].size()-1) {
        v = vec[u][i];
        if(!dfn[v]) {
            tarjan_EDGE(v,u);
            low[u] = MIN(low[u],low[v]);
        }
        else if(v != fa) {
            low[u] = MIN(low[u],dfn[v]);
        }
    }
    //low相同的在一个边双中
}
int main()
{
    cin>>n>>m;
    rep(i,1,m) {
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
    }
    rep(i,1,n) {
        //cout<<i<<endl;
        if (!dfn[i]) tarjan_SCC(i);
    }
    rep(i,1,n) cout<<belong[i]<<' ';
    cout<<endl;
    return 0;
}
/*
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6
*/
