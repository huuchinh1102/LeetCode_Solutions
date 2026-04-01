int pivotIndex(int* nums, int numsSize) {
    double tong = 0;
    double sum = 0;
    double* hieu = (double*) malloc (sizeof(double)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        hieu[i] = sum - nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (tong == hieu[i]/2) {
            return i;
        }
        tong += nums[i];
    }
    return -1;
}