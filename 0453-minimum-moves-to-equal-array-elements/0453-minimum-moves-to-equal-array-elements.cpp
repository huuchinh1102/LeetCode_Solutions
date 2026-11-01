class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = 1000000001;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min) min = nums[i];
        }
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += (nums[i] - min);
        }
        return res;
    }
};