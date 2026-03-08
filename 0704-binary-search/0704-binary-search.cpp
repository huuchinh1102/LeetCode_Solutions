class Solution {
public:
    int search(vector<int>& nums, int target) {
        int key = 0;
        int dau = 0;
        int cuoi = nums.size()-1;
        int i = nums.size()/2;
       while (dau <= cuoi) {
        if (nums[i] == target) {
            key = 1;
            break;
        }
        else if (nums[i] < target) {
            dau = i+1;
            i = (cuoi+i)/2+1;
        }
        else {
            cuoi = i-1;
            i = (dau+i)/2;
        }
       }
       if (key == 0) {
        return -1;
       }
       else {
        return i;
       }
    }
};