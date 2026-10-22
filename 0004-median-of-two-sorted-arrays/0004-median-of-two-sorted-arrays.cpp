class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i >= m) {
                res.push_back(nums2[j]);
                j++;
            }
            else if (j >= n) {
                res.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        double ans;
        if ((m+n) % 2 != 0) {
            ans = res[(m+n)/2];
        }
        else {
            ans = (res[(m+n)/2] + res[(m+n-1)/2]);
            ans /= 2;
        }
        return ans;
    }
};