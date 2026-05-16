int compare(const void *a, const void *b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}
bool isGood(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
    }
    if (numsSize-1 != max) return false;
    qsort(nums, numsSize, sizeof(int), compare);
    int cnt[1000] = {0};
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (cnt[nums[i]] != 1 && i != numsSize-2 && i != numsSize-1) return false; 
    }
    return true;
}