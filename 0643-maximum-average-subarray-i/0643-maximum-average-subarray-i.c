int max (int a, int b) {
    return a > b ? a : b;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    double temp = 0;
    int i;
    for (i = 0; i < k; i++) {
        temp += nums[i];
    }
    double max_val = temp;
    int left = 0;
    while (i <= numsSize-1) {
        temp -= nums[left];
        temp += nums[i];
        i++;
        left++;
        max_val = max(temp, max_val);
    }
    return max_val/k;
}