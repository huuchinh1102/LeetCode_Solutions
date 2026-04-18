int reverse (int n) {
    int res = 0;
    while (n > 0) {
        int a = n % 10;
        n /= 10;
        res = res*10 + a;
    }
    return res;
}

int mirrorDistance(int n) {
    int res = reverse(n);
    res = abs(res - n);
    return res;
}