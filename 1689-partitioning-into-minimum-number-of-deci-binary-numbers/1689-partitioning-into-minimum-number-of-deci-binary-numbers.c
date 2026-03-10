int minPartitions(char* n) {
    int a[100005];
    int max = 0;
    for (int i = 0; i < strlen(n); i++) {
        a[i] = n[i] - '0';
        if (a[i] > max) {
            max = a[i];
            if (max == 9) break;
        }
    }
    return max;
}