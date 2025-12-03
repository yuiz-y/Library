struct SCC{
    private:
    int n;
    vector<vector<ll>> e,er;
    stack<int> st;
    vector<bool> seen;
    vector<ll> list;

    public:

    void add_edge(int a,int b){
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

    void dfs2(int root,int f){
        list[f] = root;
        for(int t : er[f]) if(list[t]==-1) dfs2(root,t);
    }

    vector<ll> solve(){
        rep(i,n) if(seen[i]==false) dfs1(i);
        while(st.size()){
            int f = st.top();
            if(list[f]==-1) dfs2(f,f);
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
