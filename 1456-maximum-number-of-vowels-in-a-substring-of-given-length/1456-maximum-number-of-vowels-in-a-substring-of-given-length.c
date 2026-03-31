int max(int a, int b) {
    return a > b ? a : b;
}

int maxVowels(char* s, int k) {
    int len = strlen(s);
    int max_cnt = -1;
    int left = 0;
    int right = k-1;
    int cnt = 0;
    for (int i = 0; i <= k-1; i++) {
        if (s[i] == 'a'  || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            cnt++;
        }
    }
    max_cnt = max(max_cnt, cnt);
    while (right <= len-1) {
        if (s[left] == 'a'  || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
            cnt--;
        }
        left++;
        right++;
        if (s[right] == 'a'  || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
            cnt++;
        }
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
}