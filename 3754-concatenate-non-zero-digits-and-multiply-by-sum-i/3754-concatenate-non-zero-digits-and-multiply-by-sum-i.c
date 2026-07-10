long long sumAndMultiply(int n) {
    long long res = 0;
    int i = 1;
    long long sum = 0;
    while (n > 0) {
        int x = n % 10;
        sum += x;
        n /= 10;
        if (x != 0) {
            res = res + x*i;
            i *= 10;
        }
    }
    return sum*res;
}