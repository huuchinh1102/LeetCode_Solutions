#include <limits.h>

int minimumDistance(int* nums, int numsSize) {
    int cnt[1005] = {0};
    int dau[1005] = {0};
    int giua[1005] = {0};
    
    int min = INT_MAX; 
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        cnt[val]++;
        
        if (cnt[val] == 1) {
            dau[val] = i;
        } 
        else if (cnt[val] == 2) {
            giua[val] = i;
        } 
        else if (cnt[val] >= 3) {
            int cuoi = i;
            
            int res = 2 * (cuoi - dau[val]);
            if (res < min) {
                min = res;
            }
            
            dau[val] = giua[val];
            giua[val] = cuoi;
        }
    }
    return min == INT_MAX ? -1 : min;
}