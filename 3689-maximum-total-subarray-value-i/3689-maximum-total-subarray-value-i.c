long long maxTotalValue(int* nums, int numsSize, int k) {
    long long max = nums[0];
    long long min = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }
    return (max-min)*k;
}