int factorial (int n) {
    if (n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}

char* getPermutation(int n, int k) {
    int cnt = 0;
    int result[100];
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int hi;
    int temp[15];
    int i = 0;
    int x;
    int j;
    k = k-1;
    int n1 = n;
    for (int i = 0; i < n; i++) {
        temp[i] = i+1;
    }
    while (n > 0) {  
        hi = factorial(n-1);
        n--;
        x = k % hi;
        k = k / hi;
        result[i] = temp[k];
        for (j = k; j <= n1-2 ; j++) {
            temp[j] = temp[j+1];
        }
        res[i] = result[i] + '0';
        k = x;
        i++;
    }
    res[i] = '\0';
    return res;  
}