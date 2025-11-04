template<ll mod> struct rolling_hash{
    private:
    ll n,s; // mod, 長さ, 文字の種類数
    vector<modint<mod>> h,pw;
    public:
    modint<mod> get_hash(int l,int r){ // 半開区間
        return h[r]-h[l]*pw[r-l];
    }
    bool match_hash(int a,int b,int c,int d){
        return (get_hash(a,b)==get_hash(c,d));
    }
    rolling_hash(){}
    rolling_hash(string t,char c,int s){
        this->n=t.size();
        this->s=s;
        this->h=vector<modint<mod>>(n+5);
        pw=vector<modint<mod>>(n+5);
        REP(i,n){
            h[i]=(h[i]+t[i-1]-c);
            h[i+1]=h[i]*s;
        }
        pw[0]=1;
        REP(i,n) pw[i]=pw[i-1]*s;
    }
};

struct d_rolhash{
    private:
    rolling_hash<998244353> h1;
    rolling_hash<1000000007> h2;
    public:
    bool match(int a,int b,int c,int d){
        return (h1.match_hash(a,b,c,d)&&h2.match_hash(a,b,c,d));
    }
    d_rolhash(string t,char c,int s){
        this->h1=rolling_hash<998244353>(t,c,s);
        this->h2=rolling_hash<1000000007>(t,c,s);
    }
};