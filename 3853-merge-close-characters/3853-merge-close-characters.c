char* mergeCharacters(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (s[j] == s[i]) {
                if (j-i <= k) {
                    for (int x = j; x <= len-1; x++) {
                        s[x] = s[x+1];
                    }
                    len--;
                    j--;
                    i = 0;
                }
            }
        }
    }
    return s;
}