char* generateString(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    char* ans = (char*) malloc (sizeof(char)* (n+m));
    for (int i = 0; i < n+m-1; i++) {
        ans[i] = 'a';
    }
    ans[n+m-1] = '\0';
    int fixed[10600] = {0};
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = i; j <= i + m - 1; j++) {
                if (fixed[j] == 1 && ans[j] != str2[j-i]) return "";
                else {
                    fixed[j] = 1;
                    ans[j] = str2[j-i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            int ok = 0;
            for (int j = i + m - 1; j >= i; j--) {
                if (ans[j] != str2[j-i]) {
                    ok = 1;
                }
            }
            if (ok == 1) continue;
            else {
                int index = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (fixed[j] != 1 && index == -1) {
                        ans[j] = 'b';
                        index = j;
                    }
                }
                if (index == -1) return "";
            }
        }
    }
    return ans;
}