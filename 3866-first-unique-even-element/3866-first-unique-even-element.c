int firstUniqueEven(int* nums, int numsSize) {
    int res = -1;
    int cnt[105] = {0};
    for (int i = 0; i < numsSize; i++) {
       cnt[nums[i]]++;     
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0 && cnt[nums[i]] == 1) {
            res = nums[i];
            break;
        }
    }
    return res;
}