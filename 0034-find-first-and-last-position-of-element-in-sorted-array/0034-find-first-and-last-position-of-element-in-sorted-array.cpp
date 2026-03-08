class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        int left1 = 0;
        int right1 = nums.size()-1;
        int ok = 0;
        int mid1;
        vector<int> res;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (target == nums[mid]) {
                ok = 1;
                break;
            }
            else if (target < nums[mid]) {
                right = mid-1;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        mid1 = mid;
        int left2 = left1;
        int right2 = right1;
        if (ok == 1) {
            while (left1 <= right1) {
                if (target == nums[mid]) {
                    left1 = mid +1;
                }
                if (target < nums[mid]) {
                    right1 = mid-1;
                }
                mid = left1 + (right1-left1)/2;
            }
            while (left2 <= right2) {
                if (target == nums[mid1]) {
                    right2 = mid1 -1;
                }
                if (target > nums[mid1]) {
                    left2 = mid1 +1;
                }
                mid1 = left2 + (right2-left2)/2;
            }
            res.push_back(left2);
            res.push_back(right1);
            return res;
        }
        else {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
    }
};