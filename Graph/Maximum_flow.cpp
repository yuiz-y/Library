struct Maximum_flow{
    public:
    struct Edge{
        int to,cap,rev;
        Edge(int t,int c,int r){
            to=t,cap=c,rev=r;
        }
    };
    int n,inf=1234567890;
    vector<int> itr;
    vector<vector<Edge>> e;
    vector<int> lv;
    void add_edge(int a,int b,int c){
        e[a].push_back(Edge(b,c,e[b].size()));
        e[b].push_back(Edge(a,0,e[a].size()-1));
    }
    int flow(int rt,int gl,int f){
        if(rt==gl) return f;
        for(int i=itr[rt];i<e[rt].size();i++){
            Edge& ed=e[rt][i];
            if(lv[rt]<lv[ed.to]&&0<ed.cap){
                int fl=flow(ed.to,gl,min(f,ed.cap));
                if(0<fl){
                    ed.cap-=fl;
                    e[ed.to][ed.rev].cap+=fl;
                    return fl;
                }
            }
        }
        return 0;
    }
    void bfs(int s){
        rep(i,n) lv[i]=inf;
        queue<int> q;
        q.push(s);
        lv[s]=0;
        while(q.size()){
            int f=q.front(); q.pop();
            for(Edge ed:e[f]){
                int t=ed.to;
                if(lv[f]+1<lv[t]&&0<ed.cap){
                    lv[t]=lv[f]+1;
                    q.push(t);
                }
            }
        }
    }
    int solve(int st,int gl){
        int ans=0;
        while(1){
            bfs(st);
            if(lv[gl]==inf) return ans;
            rep(i,n) itr[i]=0;
            int fl;
            while(1){
                fl=flow(st,gl,inf);
                if(fl==0) break;
                ans+=fl;
            }
        }
        return 0;
    }
    Maximum_flow(int n){
        this->n=n;
        e=vector<vector<Edge>>(n);
        lv=itr=vector<int>(n);
    }
};
