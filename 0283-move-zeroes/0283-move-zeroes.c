void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;
    int x = 0, y = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            cnt++;
        }
    }
    while (x < numsSize) {
        if (nums[x] != 0) {
            nums[y] = nums[x];
            x++;
            y++;
        }
        else {
            x++;
        }
    }
    if (cnt == numsSize);
    else {
        for (int i = numsSize-cnt; i < numsSize; i++) {
            nums[i] = 0;
        }
    }
}