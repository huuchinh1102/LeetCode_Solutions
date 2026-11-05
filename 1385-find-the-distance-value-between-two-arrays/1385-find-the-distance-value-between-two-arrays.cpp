class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int ok = 1;
            for (int j = 0; j < m; j++) {
                if (arr1[i] >= arr2[j]) {
                    if ((arr1[i] - arr2[j]) <= d) {
                        ok = 0;
                        break;
                    }
                }
                else {
                    if (arr2[j] - arr1[i] <= d) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok == 1) res++;
        }
        return res;
    }
};