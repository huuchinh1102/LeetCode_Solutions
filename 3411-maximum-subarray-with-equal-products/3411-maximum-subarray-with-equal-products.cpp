class Solution {
public:
    int gcd (int a, int b) {
        if (a == b) return a;
        if (a == 1) return 1;
        int x = abs(a-b);
        return gcd(x, min(a,b));
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxcount = 2;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 1; j + i < n; j++) {
                int ok = 1;
                for (int k = i; k < j+i; k++) {
                    if (gcd(nums[k], nums[i+j]) == 1);
                    else {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 1) {
                    count++;
                    maxcount = max(count, maxcount);
                }
                else break;
            }
        }
        return maxcount;
    }
};