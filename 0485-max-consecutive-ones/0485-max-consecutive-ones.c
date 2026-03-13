int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int cnt;
    for (int i = 0; i < numsSize; i++) {
        cnt = 0;
        while (i < numsSize && nums[i] == 1) {
            cnt++;
            i++;
        }
        if (cnt > max) max = cnt;
    }
    return max;
}