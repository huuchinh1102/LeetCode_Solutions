/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minDistinctFreqPair(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    int cnt[10005] = {0};
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == 0) continue;
        for (int j = i+1; j <= 100; j++) {
            if (cnt[j] == 0) continue;
            else {
                if (cnt[i] != cnt[j]) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
    }
    result[0] = -1;
    result[1] = -1;
    return result;
}