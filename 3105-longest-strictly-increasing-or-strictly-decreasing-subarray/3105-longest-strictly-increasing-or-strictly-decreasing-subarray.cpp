class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incre = 1;
        int decre = 1;
        int maxincre = 1;
        int maxdecre = 1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] > nums[i]) {
                incre++;
                maxincre = max(maxincre, incre);
            }
            else {
                maxincre = max(maxincre, incre);
                incre = 1;
            }
            if (nums[i+1] < nums[i]) {
                decre++;
                maxdecre = max(maxdecre, decre);
            }
            else {
                maxdecre = max(maxdecre, decre);
                decre = 1;
            }
        }
        return max(maxincre, maxdecre);
    }
};