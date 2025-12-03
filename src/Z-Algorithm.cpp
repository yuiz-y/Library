vector<ll> Z_algirithm(string s){
    int n = s.size();
    vector<ll> z(n);
    z[0] = n;

    int i = 1, j = 0;
    while(i<n){
        while(i+j<n && s[j]==s[i+j]) j++;
        z[i] = j;

        // 1 文字も一致していないとき
        if(j==0){
            i++;
            continue;
        }

        // 伸ばす
        int k = 1;
        while(k<j && k+z[k]<j){
            z[i+k] = z[k];
            k++;
        }
        i += k; j -= k;
    }
    return z;
}