// 配列aの最長増加部分列の長さ
int LIS(vector<ll> a){
    int n = a.size();
    int inf = 1234567890;
    vector<ll> L(n+5,inf);
    rep(i,n){
        if(a[i]<=L[0]) L[0] = a[i];
        else{
            int l = 0, r = n+5;
            while(l+1<r){
                int k = (l+r)/2;
                if(L[k]<a[i]) l = k;
                else r = k;
            }
            L[r] = a[i];
        }
    }
    rep(i,n+5) if(L[i]==inf) return i;
    return -1;
}