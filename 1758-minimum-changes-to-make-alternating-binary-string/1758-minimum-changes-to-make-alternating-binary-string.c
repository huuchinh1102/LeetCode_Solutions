int minOperations(char* s) {
    int len = strlen(s);
    int cnt11 = 0;
    int cnt10 = 0;
    int cnt00 = 0;
    int cnt01 = 0;
    int res;
    for (int i = 0; i < len; i = i + 2) {
        if (s[i] == '1') cnt11++;
        if (s[i] == '0') cnt00++;
    }
    for (int i = 1; i < len; i = i + 2) {
        if (s[i] == '0') cnt10++;
        if (s[i] == '1') cnt01++;
    }
    if (cnt11 + cnt10 >= cnt00 + cnt01) res = len-cnt11-cnt10;
    else res = len - cnt00 - cnt01;
    return res;
}