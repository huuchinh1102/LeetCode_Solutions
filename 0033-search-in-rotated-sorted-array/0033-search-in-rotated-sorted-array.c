int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int mid = left + (right-left)/2;
    int left1 = 0;
    int right1 = mid-1;
    int left2 = mid+1;
    int right2 = numsSize-1;
    int ok = 0;
    int k = 0;
    int here = 0;
    int mid1, mid2;
    while (left1 <= right1) {
        mid1 = left1 + (right1-left1)/2;
        if (nums[mid1] > nums[mid]) {
            left1 = mid1 + 1;
            ok = 1;
        }
        else {
            right1 = mid1 - 1;
        }
    }
    while (left2 <= right2) {
        mid2 = left2 + (right2-left2)/2;
        if (nums[mid2] > nums[mid]) {
            left2 = mid2 + 1;
        }
        else {
            ok = 2;
            right2 = mid2 - 1;
        }
    }
    if (ok == 1) {
        k = left1;
    }
    else if (ok == 2) {
        k = left2;
    }
    left1 = 0;
    right1 = k-1;
    left2 = k;
    right2 = numsSize-1;
    while (left1 <= right1) {
        mid1 = left1 + (right1-left1)/2;
        if (target == nums[mid1]) {
            here = 1;
            break;
        }
        else if (target < nums[mid1]) {
            right1 = mid1-1;
        }
        else {
            left1 = mid1+1;
        }
    }
    while (left2 <= right2) {
        mid2 = left2 + (right2-left2)/2;
        if (target == nums[mid2]) {
            here = 2;
            break;
        }
        else if (target < nums[mid2]) {
            right2 = mid2-1;
        }
        else {
            left2 = mid2+1;
        }
    }
    if (here == 1) return mid1;
    else if (here == 2) return mid2;
    else return -1;
}