bool isPalindrome(int x) {
    if (x < 0) return false;
    else {
        int ok = 1;
        int res = 0;
        int a[1005];
        int i = 0;
        while (x > 0) {
            a[i] = x % 10;
            x = x / 10;
            i++;
        }
        int temp = i;
        for (int y = 0; y <= temp/2-1; y++) {
            if (a[i-1] == a[y]) {
                i--;
            }
            else {
                ok = 0;
            }
        }
        if (ok == 1) return true;
        else return false;
    }
}