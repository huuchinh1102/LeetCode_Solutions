class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        long long max1 = nums[0];
        long long max2 = 0;
        long long max3 = 0;
        long long min1 = nums[0];
        long long min2 = 1000000009;
        long long min3 = 1000000009;
        int cntmax = 0, cntmin = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= max1) max1 = nums[i];
            if (nums[i] <= min1) min1 = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max1) cntmax++;
            if (nums[i] == min1) cntmin++;
        }
        if (cntmax >= 3) {
            max2 = max1;
            max3 = max1;
        }
        if (cntmax == 2) {
            max2 = max1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= max3 && nums[i] != max1) max3 = nums[i];
            }
        }
        if (cntmax == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= max2 && nums[i] != max1) max2 = nums[i];
            }
            int cntmax2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == max2) cntmax2++;
            }
            if (cntmax2 >= 2) max3 = max2;
            else {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] >= max3 && nums[i] != max2 && nums[i] != max1) max3 = nums[i];
                }
            }
        }

        if (cntmin >= 3) {
            min2 = min1;
            min3 = min1;
        }
        if (cntmin == 2) {
            min2 = min1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= min3 && nums[i] != min1) min3 = nums[i];
            }
        }
        if (cntmin == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= min2 && nums[i] != min1) min2 = nums[i];
            }
            int cntmin2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == min2) cntmin2++;
            }
            if (cntmin2 >= 2) min3 = min2;
            else {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] <= min3 && nums[i] != min2 && nums[i] != min1) min3 = nums[i];
                }
            }
        }

        int hieu1 = max1 - min1;
        int hieu2 = max1 - min2;
        int hieu3 = max1 - min3;
        int hieu4 = abs(max2 - min1);
        int hieu5 = abs(max2 - min2);
        int hieu6 = abs(max3 - min1);
        return min({hieu1, hieu2, hieu3, hieu4, hieu5, hieu6});
    }
};