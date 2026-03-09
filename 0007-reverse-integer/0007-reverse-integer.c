int reverse(int x){
    int res = 0;
    int negative;
    if (x >= 0) negative = 0;
    else negative = 1;
    while (negative == 0 && x > 0) {
        int digit = x % 10;
        x = x/10;
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
            res = 0;
            break;
        }
        else {
            res = res * 10 + digit;
        }
    }
    while (negative == 1 && x < 0) {
        int digit = x % 10;
        x = x/10;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) {
            res = 0;
            break;
        }
        else {
            res = res * 10 + digit;
        }
    }
    return res;
}