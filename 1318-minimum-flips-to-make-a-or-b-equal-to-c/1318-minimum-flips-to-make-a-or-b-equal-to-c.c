

int minFlips(int a, int b, int c){
    int temp = a;
    int remain_a[36];
    int cnt_a = 0;
    while (temp > 0) {
        remain_a[cnt_a] = temp % 2;
        temp /= 2;
        cnt_a++;
    }
    temp = b;
    int remain_b[36];
    int cnt_b = 0;
    while (temp > 0) {
        remain_b[cnt_b] = temp % 2;
        temp /= 2;
        cnt_b++;
    }
    temp = c;
    int remain_c[36];
    int cnt_c = 0;
    while (temp > 0) {
        remain_c[cnt_c] = temp % 2;
        temp /= 2;
        cnt_c++;
    }
    int max;
    if (a >= b && a >= c) max = a;
    else if (b >= c && b >= a) max = b;
    else max = c;
    int count = 0;
    if (max == a) {
        for (int i = cnt_a-1; i >= cnt_b; i--) {
            remain_b[i] = 0;
        }
        for (int i = cnt_a-1; i >= cnt_c; i--) {
            remain_c[i] = 0;
        }
    }

    if (max == b) {
        for (int i = cnt_b-1; i >= cnt_c; i--) {
            remain_c[i] = 0;
        }
        for (int i = cnt_b-1; i >= cnt_a; i--) {
            remain_a[i] = 0;
        }
        cnt_a = cnt_b;
    }

    if (max == c) {
        for (int i = cnt_c-1; i >= cnt_b; i--) {
            remain_b[i] = 0;
        }
        for (int i = cnt_c-1; i >= cnt_a; i--) {
            remain_a[i] = 0;
        }
        cnt_a = cnt_c;
    }
    for (int i = 0; i <= cnt_a - 1; i++) {
        if ((remain_a[i] | remain_b[i]) == remain_c[i]) continue;
        else if (remain_c[i] == 0) {
            if (remain_a[i] == 1 && remain_b[i] == 1) count += 2;
            else count++;
        }
        else count++;
    }
    return count;
}