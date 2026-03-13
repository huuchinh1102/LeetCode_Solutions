char* reverseWords(char* s) {
    char* ans = (char*) malloc (sizeof(char)*strlen(s)+1);
    int len = strlen(s);
    int left = 0;
    int right = len-1;
    int x = 0;
    while (s[left] == ' ') left++;
    while (s[right] == ' ')  right--;
    for (int i = left; i < right; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            for (int j = i+1; j < right; j++) {
                s[j] = s[j+1];
            }
            right--;
            i--;
        }
    }
    int a = right+1;
    for (int i = right; i >= left; i--) {
        if (s[i] == ' ' && a == right+1) {
            for (int j = i+1; j < a; j++) {
                ans[x] = s[j];
                x++;
            }
            a = i;
            ans[x] = ' ';
            x++;
        }
        else if (s[i] == ' ') {
            for (int j = i+1; j <= a; j++) {
                ans[x] = s[j];
                x++;
            }
            a = i;
        }
        else if (i == left) {
            for (int j = i; j < a; j++) {
                ans[x] = s[j];
                x++;
            }
        }
    }
    ans[x] = '\0';
    return ans;
}