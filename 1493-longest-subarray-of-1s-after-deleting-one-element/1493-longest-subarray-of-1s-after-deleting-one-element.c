int max (int a, int b) {
    return a > b ? a : b;
}

int longestSubarray(int* nums, int numsSize) {
    int left = 0;
    int zero_count = 0;
    int max_cnt = 0;
    int cnt = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zero_count++;
        }
        while (zero_count > 1) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }
        cnt = right - left + 1;
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt-1;
}