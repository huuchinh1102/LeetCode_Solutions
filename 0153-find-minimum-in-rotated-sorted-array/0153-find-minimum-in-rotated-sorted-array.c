int findMin(int* nums, int numsSize) {
    int mid = numsSize/2;
    int left1 = 0;
    int right1 = mid-1;
    int left2 = mid+1;
    int right2 = numsSize-1;
    int mid1, mid2;
    int ok = 0;
    int k;
    while (left1 <= right1) {
        mid1 = left1 + (right1-left1)/2;
        if (nums[mid1] > nums[mid]) {
            left1 = mid1+1;
            ok = 1;
        }
        else {
            right1 = mid1-1;
        }
    }
    while (left2 <= right2) {
        mid2 = left2 + (right2-left2)/2;
        if (nums[mid2] < nums[mid]) {
            right2 = mid2-1;
            ok = 2;
        }
        else {
            left2 = mid2+1;
        }
    }
    if (ok == 1) k = left1;
    else if (ok == 2) k = left2;
    else k = 0;
    return nums[k];
}