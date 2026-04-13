int getMinDistance(int* nums, int numsSize, int target, int start) {
    int min = 1000;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            int res = abs(start - i);
            if (res <= min) min = res;
        }
    }
    return min;
}