bool checkOnesSegment(char* s) {
    int len = strlen(s);
    int ok = 1;
    if (s[1] == '0') {
        for (int i = 2; i < len; i++) {
            if (s[i] == '1') {
                ok = 0;
                break;
            }
        }
    }
    else {
        int j = 2;
        while (j < len && s[j] == '1') {
            j++;
        }
        if (j >= len-1) ok = 1;
        else {
            for (int x = j; x < len; x++) {
                if (s[x] == '1') {
                    ok = 0;
                    break;
                }
            }
        }  
    }
    if (ok == 0) return false;
    else return true;
}