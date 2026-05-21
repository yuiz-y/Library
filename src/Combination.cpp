template<typename T> struct factorial{
    private:
    vector<T> a, b;
    public:
    T comb(ll n, ll k){
        if(k<0 || n<k) return 0;
        return a[n]*b[n-k]*b[k];
    }
    factorial(int n){
        a.resize(n+10,1);
        b.resize(n+10,1);
        REP(i,n) a[i+1] = a[i]*(i+1);
        b[n+1] = 1/a[n+1];
        for(int i=n; 0<i; i--) b[i] = b[i+1]*(i+1);
    }
};