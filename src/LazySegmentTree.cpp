template<class T,class E,T op_id,E ef_id,T(*op)(T,T),void(*ch)(T&,E),void(*sy)(E&,E)>
struct LazySegmentTree{
    private:
    int n = 1;
    vector<T> k;
    vector<E> lazy;
    vector<bool> flag;
    public:
    void eval(int i,int l,int r){
        if(flag[i]){
            ch(k[i],lazy[i]);
            if(l+1<r){
                sy(lazy[2*i],lazy[i]);
                sy(lazy[2*i+1],lazy[i]);
                flag[2*i] = flag[2*i+1] = true;
            }
            flag[i] = false;
            lazy[i] = ef_id;
        }
    }
    void update(int a,int b,int i,int l,int r,E x){
        eval(i,l,r);
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            sy(lazy[i],x);
            flag[i] = true;
            eval(i,l,r);
        }
        else{
            update(a,b,i*2,l,(l+r)/2,x);
            update(a,b,i*2+1,(l+r)/2,r,x);
            k[i] = op(k[i*2],k[i*2+1]);
        }
    }
    void update(int a,int b,E x){
        update(a,b,1,0,n,x);
    }
    T query(int a,int b,int i,int l,int r){
        eval(i,l,r);
        if(r<=a || b<=l) return op_id;
        if(a<=l && r<=b) return k[i];
        T v1 = query(a,b,i*2,l,(l+r)/2);
        T v2 = query(a,b,i*2+1,(l+r)/2,r);
        return op(v1,v2);
    }
    T query(int a, int b) {
        return query(a,b,1,0,n);
    }
    LazySegmentTree(vector<T> a){
        int m = a.size();
        while(n<m) n *= 2;
        k = vector<T>(n*2,op_id);
        lazy = vector<E>(n*2,ef_id);
        flag = vector<bool>(n*2,false);
        rep(i,m) k[n+i] = a[i];
        for(int i=n-1;0<i;i--) k[i] = op(k[i*2],k[i*2+1]);
    }
};