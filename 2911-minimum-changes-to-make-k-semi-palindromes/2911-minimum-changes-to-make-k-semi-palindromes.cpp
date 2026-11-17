class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d <= n / 2; ++d) {
            for (int len = 2 * d; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;

                for (int d : divisors[len]) {
                    int changes = 0;

                    for (int g = 0; g < d; ++g) {
                        int left = l + g;
                        int right = left + len - d;

                        while (left < right) {
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 2 * parts; i <= n; ++i) {
                for (int j = 2 * (parts - 1); j <= i - 2; ++j) {
                    dp[parts][i] = min(dp[parts][i],
                                       dp[parts - 1][j] + cost[j][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};