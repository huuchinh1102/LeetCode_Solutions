int compare (const void *a, const void *b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}

int singleNumber(int* nums, int numsSize) {
    int res = 30001;
    qsort(nums, numsSize, sizeof(int), compare);
    if (numsSize == 1) return nums[0];
    else {
        for (int i = 1; i < numsSize; i = i+2) {
            if (nums[i] != nums[i-1]) {
                res = nums[i-1];
                break;
            }
        }
        if (res == 30001) res = nums[numsSize-1];
    }
    return res;
}