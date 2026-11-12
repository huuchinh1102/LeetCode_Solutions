class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector <int> dp(n, 0);
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            if (i + nums[i] >= n-1) {
                res++;
                break;
            }
            for (int j = 1; j <= nums[i]; j++) {
                dp[i] = max(i+j + nums[i+j], dp[i]);
            }
            for (int j = 1; j <= nums[i]; j++) {
                if (dp[i] == i+j+nums[i+j]) {
                    i = i+j-1;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};