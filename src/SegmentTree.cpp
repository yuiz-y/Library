template<class T, T id, T (*op)(T,T)>
struct SegmentTree{
    private:
    int n = 1;
    vector<T> k;
    public:
    T at(int i){
        return k[n+i];
    }
    void update(int i, T x){
        i = n+i;
        k[i] = x;
        while(1<i){
            i /= 2;
            k[i] = op(k[i*2], k[i*2+1]);
        }
    };
    T query(int l, int r){
        T x = id, y = id;
        l += n; r += n;
        while(l<r){
            if(l&1) x = op(x, k[l++]);
            if(r&1) y = op(k[--r], y);
            l >>= 1; r >>= 1;
        }
        return op(x, y);
    }
    SegmentTree(vector<T> a){
        int m = a.size();
        while(n<=m+1) n *= 2;
        this->k = vector<T>(n*4, id);
        rep(i,m) k[n+i] = a[i];
        for(int i=n-1; 0<i; i--) k[i] = op(k[i*2], k[i*2+1]);
    }
};