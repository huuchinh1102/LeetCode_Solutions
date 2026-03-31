int max(int a, int b) {
    return a > b ? a : b;
}

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int max_cnt = 0;
    int zero_count = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zero_count++;
        }
        while (zero_count > k) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }
        int len = right-left+1;
        if (len > max_cnt) max_cnt = len;
    }
    return max_cnt;
}