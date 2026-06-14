/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int dup, missing;
    int cnt[10005] = {0};
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 1; i <= numsSize; i++) {
        if (cnt[i] == 2) dup = i;
        if (cnt[i] == 0) missing = i;
    }
    result[0] = dup;
    result[1] = missing;
    return result;
}