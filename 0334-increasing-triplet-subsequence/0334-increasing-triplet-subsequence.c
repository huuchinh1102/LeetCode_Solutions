bool increasingTriplet(int* nums, int numsSize) {
    int min1 = INT_MAX;
    int min2 = min1;
    int min3 = min1;
    int ok = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min1) min1 = nums[i];
        else if (nums[i] <= min2) min2 = nums[i];
        else if (nums[i] <= min3) {
            min3 = nums[i];
            ok = 1;
        }
    }
    if (ok == 0) return false;
    else return true;
}