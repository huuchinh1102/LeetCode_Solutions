long gcd (long c, long d) {
    while (d != 0) {
        long temp = d;
        d = c % d;
        c = temp;
    }
    return c;
}
char* gcdOfStrings(char* str1, char* str2) {
    long a = strlen(str1);
    long b = strlen(str2);
    char * mang1 = (char*) malloc(sizeof(char)*(a+b+1));
    char * mang2 = (char*) malloc(sizeof(char)*(a+b+1));
    char * result = (char*) malloc(sizeof(char)*(a+b+1));
    int i = 0,  j = 0, n, x, y;
    long res;
    int ok = 1;
    int m = 0;
    int Bayern = 0;
    for (i = 0; i < a; i++) {
        mang1[i] = str1[i];
    }
    for (i = a, x = 0; i < a+b, x < b; i++, x++) {
        mang1[i] = str2[x];
    }
    mang1[i] = '\0';
    for (j = 0; j < b; j++) {
        mang2[j] = str2[j];
    }
    for (j = b, y = 0; j < a+b, y < a; j++, y++) {
        mang2[j] = str1[y];
    }
    mang2[j] = '\0';
    for (int k = 0; k < a+b; k++) {
        if (mang1[k] != mang2[k]) {
            ok = 0;
        }
    }
    free(mang1);
    free(mang2);
    if (ok == 0) return "";
    else {
        res = gcd(a,b);
        while (str1[m] == str2[m]) {
            if (m == res-1) {
                Bayern = 1;
                break;
            }
            m++;
        }
        if (Bayern == 1) {
            for (n = 0; n < res; n++) {
            result[n] = str1[n];
            }
            result[n] = '\0';
            return result;
        }
        else return "";
    } 
}