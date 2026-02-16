vll comp(vll a){
    vll b = a; sort(b);
    b.erase(unique(all(b)), b.end());
    for(auto &x : a) x = lower_bound(all(b), x)-b.begin();
    return a;
}