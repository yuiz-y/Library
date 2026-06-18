struct LCA_Tree{
    private:
    int n, inf = 1234567890, ldp = 25; // ldp : log{深さの最大値}
    vector<vector<ll>> dp;
    vector<ll> deep;
    public:
    int up(int x, int k){ // x から k 世代上へ
        rep(j,ldp) if((k>>j)&1==1) x = dp[x][j];
        return x;
    }
    int lca(int x, int y){ // x と y の LCA
        int p = min(deep[x], deep[y]);
        x = up(x, deep[x]-p);
        y = up(y, deep[y]-p);
        if(x==y) return x;

        rrep(j,ldp) if(up(x, 1<<j)!=up(y, 1<<j)){
            x = up(x, 1<<j);
            y = up(y, 1<<j);
        }
        return up(x, 1);
    }
    int dis(int x, int y){ // x と y の距離
        return deep[x]+deep[y]-deep[lca(x,y)]*2;
    }
    LCA_Tree(int n, vector<vll> e){
        dp = vector<vector<ll>>(n,vector<ll>(ldp+5));
        deep = vector<ll>(n, inf);
        queue<int> q;
        q.push(0); deep[0] = 0;
        while(q.size()){
            int f = q.front(); q.pop();
            for(int t : e[f]) if(deep[f]+1<deep[t]){
                deep[t] = deep[f]+1;
                q.push(t);
            }
        }
        rep(f,n) for(int t : e[f]) if(deep[f]+1==deep[t]) dp[t][0] = f;
        rep(j,ldp) rep(i,n) dp[i][j+1] = dp[dp[i][j]][j];
    }
};
