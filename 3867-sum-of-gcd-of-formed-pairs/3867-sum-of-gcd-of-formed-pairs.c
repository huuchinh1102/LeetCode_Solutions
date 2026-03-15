long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int compare(const void *a, const void *b) {
    if (*(long long*)a > *(long long*)b) return 1;
    if (*(long long*)a < *(long long*)b) return -1;
    return 0;
}

long long gcdSum(int* nums, int numsSize) {
    long long prefixGcd[100005];
    long long max_val = (long long)nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= max_val) max_val = nums[i];
        prefixGcd[i] = gcd(nums[i], max_val);
    }
    qsort(prefixGcd, numsSize, sizeof(long long), compare);
    long long res = 0;
    long long left = 0;
    long long right = numsSize-1;
    while (left < right) {
        res += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return res;
}