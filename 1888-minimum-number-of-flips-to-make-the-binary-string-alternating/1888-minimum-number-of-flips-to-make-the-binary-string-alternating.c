int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

int minFlips(char* s) {
    int n = strlen(s);
    char * ans = (char*) malloc (sizeof(char)*2*n);
    for (int i = 0; i < 2*n; i++) {
        ans[i] = s[i % n];
    }   
    char * s1 = (char*) malloc (sizeof(char)*2*n);
    char * s2 = (char*) malloc (sizeof(char)*2*n);
    for (int i = 0; i < 2*n; i++) {
        if (i % 2 == 0) {
            s1[i] = '0';
            s2[i] = '1';
        }
        else {
            s1[i] = '1';
            s2[i] = '0';
        }
    }
    int ans1 = 0;
    int ans2 = 0;
    int res = INT_MAX;
    for (int i = 0; i < 2*n; i++) {
        if (ans[i] != s1[i]) ans1++;
        if (ans[i] != s2[i]) ans2++;
        if (i >= n) {
            if (ans[i-n] != s1[i-n]) ans1--;
            if (ans[i-n] != s2[i-n]) ans2--;
        }
        if (i >= n-1) {
            res = min(ans1, ans2, res);
        }
    }
    return res;
}