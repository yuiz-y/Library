struct LCA_Tree{
    private:
    int n;
    vector<V> dp;
    V deep;
    public:
    int up(int x,int k){
        rep(j,25) if((k>>j)&1==1) x=dp[x][j];
        return x;
    };
    int lca(int x,int y){
        int p=min(deep[x],deep[y]);
        x=up(x,deep[x]-p);
        y=up(y,deep[y]-p);
        if(x==y) return x;
        int l=0,r=p+5;
        while(l+1<r){
            int m=(l+r)/2;
            if(up(x,m)==up(y,m)) r=m;
            else l=m;
        }
        return up(x,r);
    };
    int dis(int x,int y){
        return deep[x]+deep[y]-deep[lca(x,y)]*2;
    };
    LCA_Tree(int n,vector<V> e){
        dp=vector<V>(n,V(30));
        deep=V(n,inf);
        queue<int> q;
        q.push(0); deep[0]=0;
        while(q.size()){
            int f=q.front(); q.pop();
            for(int t:e[f]) if(deep[f]+1<deep[t]){
                deep[t]=deep[f]+1;
                q.push(t);
            }
        }
        rep(f,n) for(int t:e[f]) if(deep[f]+1==deep[t]) dp[t][0]=f;
        rep(j,25) rep(i,n) dp[i][j+1]=dp[dp[i][j]][j];
    };
};
