class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> minn(n+1);
        if (n == 1) return costs[0] + 1;
        if (n == 2) return min(costs[0] + costs[1] + 2, costs[1] + 4);
        else {
            minn[1] = costs[0] + 1;
            minn[2] = min(minn[1] + costs[1] + 1, costs[1] + 4);
            minn[3] = min({minn[2] + costs[2] + 1, costs[1] + costs[2] + 5, costs[0] + costs[2] + 5, costs[2] + 9});
        }
        for (int i = 4; i <= n; i++) {
            minn[i] = min({minn[i-1] + costs[i-1] + 1, minn[i-2] + costs[i-1] + 4, minn[i-3] + costs[i-1] + 9});
        }
        return minn[n];
    }
};