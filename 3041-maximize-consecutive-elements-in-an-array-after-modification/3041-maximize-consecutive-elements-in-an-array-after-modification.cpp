class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1000005);
        int ans = 0;
        for (int x : nums) {
            dp[x+1] = max(dp[x]+1, dp[x+1]);
            dp[x] = max(dp[x-1]+1, dp[x]);
            ans = max({ans, dp[x+1], dp[x]});
        }
        return ans;
    }
};