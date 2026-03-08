int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}

int maxOperations(int* nums, int numsSize, int k){
    int res = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0;
    int right = numsSize-1;
    while (left < right) {
        if (nums[left] + nums[right] > k) {
            right--;
        }
        else if (nums[left] + nums[right] < k) {
            left++;
        }
        else {
            res++;
            left++;
            right--;
        }
    }
    return res;
}