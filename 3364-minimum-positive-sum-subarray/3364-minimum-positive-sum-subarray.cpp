class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minn = 1000000009;
        for (int i = l; i <= r; i++) {
            int size = i;
            for (int j = 0; j <= nums.size() - size; j++) {
                int sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += nums[j+k];
                }
                if (sum > 0) minn = min(minn, sum);
            }
        }
        if (minn == 1000000009) return -1;
        else return minn;
    }
};