struct SCC{
    private:
    int n;
    vector<vector<ll>> e,er;
    stack<int> st;
    vector<bool> seen;
    vector<ll> list;

    public:

    // a->b の辺を張る
    void add_edge(int a, int b){
        e[a].push_back(b);
        er[b].push_back(a);
    }

    void dfs1(int f){
        seen[f] = true;
        for(int t : e[f]) if(seen[t]==false){
            seen[t] = true;
            dfs1(t);
        }
        st.push(f);
    }

    void dfs2(int root, int f){
        list[f] = root;
        for(int t : er[f]) if(list[t]==-1) dfs2(root, t);
    }

    // 連結成分を表す vector<ll>、list[i] := 頂点 i が属する強連結成分の代表頂点
    vector<ll> solve(){
        rep(i,n) if(seen[i]==false) dfs1(i);
        while(st.size()){
            int f = st.top();
            if(list[f]==-1) dfs2(f, f);
            st.pop();
        }
        return list;
    }

    SCC(int n){
        this->n = n;
        e = er = vector<vector<ll>>(n);
        seen = vector<bool>(n,false);
        list = vector<ll>(n,-1);
    }

};

// まず add_edge ですべての辺を追加する
// solve -> i 番目が頂点 i の属する各連結成分の代表 (root) を指す配列