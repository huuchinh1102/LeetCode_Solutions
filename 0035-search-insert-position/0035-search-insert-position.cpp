class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int ok = 0;
        int mid;
        if (target < nums[0]) {
            ok = -2;
        }
        if (target > nums[nums.size()-1]) {
            ok = 2;
        }
        while (left <= right) {
            mid = left + (right-left)/2;
            if (target < nums[mid]) {
                right = mid-1;
            }
            if (target > nums[mid]) {
                left = mid+1;
            }
            if (target == nums[mid]) {
                ok = 1;
                break;
            }
        }
        if (ok == 1) {
            return mid;
        }
        else if (ok == 0) {
            return left;
        }
        else if (ok == -2) {
            return 0;
        }
        else return nums.size();
    }
};