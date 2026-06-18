vll Z_algirithm(string s){ // z[i] := 先頭からと i 文字目からで何文字一致するか
    int n = s.size();
    vll z(n);
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