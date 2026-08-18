class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) {
            int max = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] >= max) max = nums[i];
            }
            return max;
        }
        if (k == 1) {
            std::sort(nums.begin(), nums.end());
            int cnt[100] = {0};
            for (int i = 0; i < nums.size(); i++) {
                cnt[nums[i]]++;
            }
            for (int i = nums.size()-1; i >= 0; i--) {
                if (cnt[nums[i]] == 1) return nums[i];
            }
            return -1;
        }
         int head1 = nums[0];
        int head2 = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == head1) {
                head1 = -1;
                break;
            }
        }
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == head2) {
                head2 = -1;
                break;
            }
        }
        if (head1 == -1 || head1 < head2) return head2;
        if (head2 == -1 || head2 < head1) return head1;
        return 0;
    }
};