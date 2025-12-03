struct UnionFind{
    private:
    vector<int> k;
    public:
    int root(int i){
        if(k[i]<0) return i;
        else return k[i] = root(k[i]);
    }
    void unite(int i,int j){
        i = root(i); j = root(j);
        if(i==j) return;
        if(size(i)<size(j)) swap(i,j);
        k[i] += k[j];
        k[j] = i;
        return;
    }
    bool connected(int x,int y){
        return (root(x)==root(y));
    }
    int size(int i){
        return k[root(i)]*-1;
    }
    UnionFind(int n){
        k=vector<int>(n,-1);
    }
};