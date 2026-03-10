int numSteps(char* s) {
    int cnt = 0;
    int len = strlen(s);
    int ok = 0;
    int hi = 1;
    for (int i = 0; i <= len-1; i++) {
        if (s[i] == '1') continue;
        else {
            hi = 0;
            break;
        }
    }
    if (hi == 1) {
        for (int i = 1; i <= len-1; i++) {
            s[i] = '0';
        }
        s[0] = '1';
        cnt = 2;
    }
    if (hi == 1 && len == 1) {
        return 0;
    }
    while (ok != 1) {
        ok = 1;
        if (s[len-1] == '1') {
            cnt++;
            for (int i = len-1; i >= 0; i--) {
                if (s[i] == '0') {
                    s[i] = '1';
                    break;
                }
                else {
                    s[i] = '0';
                }
            }
        }
        else if (s[len-1] == '0') {
            cnt++;
            for (int i = len-1; i >= 0; i--) {
                s[i+1] = s[i];
            }
            s[0] = '0';
        }
        for (int i = 0; i < len-1; i++) {
            if (s[i] == '0') continue;
            else {
                ok = 0;
                break;
            }
        }
        if (ok == 1 && s[len-1] == '1') ok = 1;
        else ok = 0; 
    }
    return cnt;
}