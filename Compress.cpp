vll comp(vll a, int start = 0){
    int n = a.size();
    set<ll> s;
    map<ll,ll> m;
    rep(i,n) s.insert(a[i]);
    int i = start;
    while(s.size()){
        ll f = *s.begin();
        s.erase(s.begin());
        m[f] = i;
        i++;
    }
    rep(i,n) a[i] = m[a[i]];
    return a;
}