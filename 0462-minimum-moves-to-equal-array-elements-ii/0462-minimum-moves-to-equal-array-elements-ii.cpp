class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median;
        long long res = 0;
        if (nums.size() % 2 != 0) {
            median = nums[nums.size()/2];
        }
        else {
            median = (nums[nums.size()/2] + nums[nums.size()/2 -1])/2;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= median) res += (nums[i] - median);
            else res += (median - nums[i]);
        }
        return res;
    }
};