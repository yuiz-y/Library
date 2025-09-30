struct SCC{
    private:
    int n;
    vector<V> e,er;
    stack<int> st;
    vector<bool> seen;
    V list;

    public:

    void add_edge(int a,int b){
        e[a].push_back(b);
        er[b].push_back(a);
    }

    void dfs1(int f){
        seen[f]=true;
        for(int t:e[f]) if(seen[t]==false){
            seen[t]=true;
            dfs1(t);
        }
        st.push(f);
    }

    void dfs2(int root,int f){
        list[f]=root;
        for(int t:er[f]) if(list[t]==-1) dfs2(root,t);
    }

    V solve(){
        rep(i,n) if(seen[i]==false) dfs1(i);
        while(st.size()){
            int f=st.top();
            if(list[f]==-1) dfs2(f,f);
            st.pop();
        }
        return list;
    }

    SCC(int n){
        this->n=n;
        e=er=vector<V>(n);
        seen=vector<bool>(n,false);
        list=V(n,-1);
    }

};
