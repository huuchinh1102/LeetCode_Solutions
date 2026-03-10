int divide(int dividend, int divisor) {
    int ok = 0;
    int res;
    int y;
    if (dividend == -2147483648) {
        if (divisor == -1) return 2147483647;
        else if (divisor == 1) return -2147483648;
        else if (divisor == 2147483648) return -1;
        else if (divisor == -2147483648) return 1;
        else {
            dividend = 2147483647;
            int x = dividend % divisor;
            if (divisor > 0 && x == divisor-1) {
                y = dividend/divisor +1;
                y = 0 - y;
            }
            else if (divisor < 0 && x == divisor+1) {
                y = dividend/divisor -1;
                y = 0-y;
            }
            else {
                y = dividend/divisor;
                y = 0 - y;
            }
            return y;
        }
    }
    else if (dividend < 0) {
        dividend = 0 - dividend;
        ok = 1;
    }
    if (ok == 1) {
        res = dividend/divisor;
        res = 0 - res;
    }
    else {
        res = dividend/divisor;
    }
    return res;
}