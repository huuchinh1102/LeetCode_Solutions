int minimumDistance(int* nums, int numsSize) {
    int cnt[100005] = {0};
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    int dem[100005] = {0};
    int dau[100005] = {0};
    int giua[100005] = {0};
    int cuoi[100005] = {0};
    int min = 1000000;
    for (int i = 0; i < numsSize; i++) {
        if (cnt[nums[i]] >= 3) {
            dem[nums[i]]++;
            if (dem[nums[i]] == 1) {
                dau[nums[i]] = i;
            }
            if (dem[nums[i]] == 2) {
                giua[nums[i]] = i;
            }
            if (dem[nums[i]] == 3) {
                cuoi[nums[i]] = i;
            }
            if (dem[nums[i]] > 3) {
                dau[nums[i]] = giua[nums[i]];
                giua[nums[i]] = cuoi[nums[i]];
                cuoi[nums[i]] = i;
            }
            if (dem[nums[i]] >= 3) {
                int res = 2 * (cuoi[nums[i]] - dau[nums[i]]);
                if (res < min) min = res;
            }
        }
    }
    if (min == 1000000) return -1;
    return min;
}