char* reverseVowels(char* s) {
    int len = strlen(s);
    int left = 0;
    int right = len-1;
    int ok = 0;
    while (left <= right) {
        if (s[left] == 'a' || s[left] == 'A' || s[left] == 'e' || s[left] == 'E' || s[left] == 'i' || s[left] == 'I' || s[left] == 'o' || s[left] == 'O' || s[left] == 'u' || s[left] == 'U') {
            if (s[right] == 'a' || s[right] == 'A' || s[right] == 'e' || s[right] == 'E' || s[right] == 'i' || s[right] == 'I' || s[right] == 'o' || s[right] == 'O' || s[right] == 'u' || s[right] == 'U') {
                char c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
            else {
                right--;
            }
        }
        else {
            left++;
        }
    }
    return s;
}