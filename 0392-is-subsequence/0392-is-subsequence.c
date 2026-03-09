bool isSubsequence(char* s, char* t) {
    int a = strlen(s);
    int b = strlen(t);
    int i = 0, x = 0;
    while (x < b && i < a) {
        if (s[i] == t[x]) {
            i++;
            x++;
        }
        else {
            x++;
        }
    }
    if (i < a) {
        return false;
    }
    else return true;
}