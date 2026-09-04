template<char a, int size>
struct TrieTree{
    int n = 1, m = 0; // 現在の頂点数と単語数
    vector<vector<int>> e;
    vector<int> bfr;

    // 1 文字進む、存在しなければ新設
    int next(int x, char c){
        if(e[x][c-a]==-1){
            e[x][c-a] = n;
            bfr[n] = x;
            n++;
        }
        return e[x][c-a];
    }

    // ある文字列に対応する頂点番号、存在しなければ新設
    int get(string s){
        int x = 0;
        for(char c : s) x = next(x, c);
        return x;
    }

    // ある文字列に対応する頂点番号、存在しなければ -1
    int find(string s){
        int x = 0;
        for(char c : s){
            if(e[x][c-a]==-1) return -1;
            x = e[x][c-a];
        }
        return x;
    }

    TrieTree(int N){
        this->e = vector<vector<int>>(N, vector<int>(size, -1));
        this->bfr = vector<int>(N);
    }
};