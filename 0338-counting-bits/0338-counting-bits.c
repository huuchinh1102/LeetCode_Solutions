/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n+1;
    int * ans = (int*) malloc (sizeof(int)*(n+1));
    for (int i = 0; i <= n; i++) {
        int sum = 0;
        int num = i;
        while (num != 0) {
            sum += num % 2;
            num /= 2;
        }
        ans[i] = sum;
    }
    return ans;
}