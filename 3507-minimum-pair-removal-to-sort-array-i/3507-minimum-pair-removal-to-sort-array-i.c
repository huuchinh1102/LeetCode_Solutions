int minimumPairRemoval(int* nums, int numsSize) {
    int tong[1005];
    int index;
    int cnt = 0;
    int ok = 0;
    int okip = 1;
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] <= nums[i+1]) {
            continue;
        }
        else {
            okip = 0;
        }
    }
    if (okip == 1) {
        return 0;
    }
    else {
        while (ok != 1) {
        ok = 1;
        int min = 50001;
        for (int i = 0; i < numsSize-1-cnt; i++) {
            tong[i] = nums[i] + nums[i+1];
            if (tong[i] < min) {
                min = tong[i];
                index = i;
            }
        }
        cnt++;
        nums[index] = nums[index] + nums[index+1];
        for (int i = index+1; i <= numsSize - 1 - cnt; i++) {
            nums[i] = nums[i+1];
        }
        for (int i = 0; i <= numsSize - 2 - cnt; i++) {
            if (nums[i] <= nums[i+1]) {
                continue;
            }
            else {
                ok = 0;
            }
        }
    }
    return cnt;
    }
}