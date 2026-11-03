class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) max = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            res += (max - nums[i]);
        }
        return res;
    }
};