

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int *ans = (int*) malloc (sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i = i+2) {
        ans[i] = nums[i/2];
    }
    int j = n;
    for (int i = 1; i < numsSize; i = i+2) {
        ans[i] = nums[j];
        j++; 
    }
    return ans;
}