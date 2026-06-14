/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int cnt[100005] = {0};
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    int j = 0;
    int* result = (int*)malloc(sizeof(int)*numsSize);
    for (int i = 1; i < numsSize+1; i++) {
        if (cnt[i] == 0) {
            result[j] = i;
            j++;
        }
    }
    *returnSize = j;
    return result;
}