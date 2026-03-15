int compare(const void *a, const void *b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}

int minCost(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int temp[160005] = {0};
    int result = 0;
    int cnt[160005] = {0};
    int visit[160005] = {0};
    int *res = (int*) malloc (sizeof(int)*(nums1Size+nums2Size));
    for (int i = 0; i < nums1Size; i++) {
            res[i] = nums1[i];
    }
    int x = 0;
    for (int j = nums1Size; j < nums1Size + nums2Size; j++) {
        res[j] = nums2[x];
        x++;
    }
    qsort(res, nums1Size+nums2Size, sizeof(int), compare);
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        cnt[res[i]]++;
    }
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        if (cnt[res[i]] % 2 != 0) {
            result = -1;
            break;
        }
    }
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        cnt[res[i]] = 0;
    }
    if (result != -1) {
        for (int i = 0; i < nums1Size; i++) {
            cnt[nums1[i]]++;
        }
        for (int i = 0; i < nums1Size; i++) {
            temp[nums1[i]] = cnt[nums1[i]];
        }
        for (int i = 0; i < nums1Size; i++) {
            cnt[nums1[i]] = 0;
        }
        for (int i = 0; i < nums2Size; i++) {
            cnt[nums2[i]]++;
        }
        for (int i = 0; i < nums1Size; i++) {
            if (visit[nums1[i]] == 0 && temp[nums1[i]] > cnt[nums1[i]]) {
                visit[nums1[i]]++;
                result += abs(temp[nums1[i]] - cnt[nums1[i]])/2; 
            }
        }
    }
    return result;
}