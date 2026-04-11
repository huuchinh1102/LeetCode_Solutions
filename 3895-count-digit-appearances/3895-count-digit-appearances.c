int countDigitOccurrences(int* nums, int numsSize, int digit) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0) {
            int hi = nums[i] % 10;
            nums[i] /= 10;
            if (hi == digit) {
                res++;
            }
        }
    }
    return res;
}