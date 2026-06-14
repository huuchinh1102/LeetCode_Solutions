/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = 0;
    }
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                result[i]++;
            }
        }
    }
    return result;
}