

int concatenatedBinary(int n){
    int x = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int i1 = i;
        while (i > 0) {
            i = i/2;
            x++;
        }
        i = i1;
        for (int j = 1; j <= x; j++) {
            res = res*2;
            res = res % 1000000007;
        }
        res += i;
        x = 0;
        res = res % 1000000007;
    }
    return res;
}