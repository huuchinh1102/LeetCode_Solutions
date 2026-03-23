int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    long long MOD = 1000000007;

    long long max_dp[15][15];
    long long min_dp[15][15];

    max_dp[0][0] = grid[0][0];
    min_dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
        min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        max_dp[0][j] = max_dp[0][j-1] * grid[0][j];
        min_dp[0][j] = min_dp[0][j-1] * grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            long long val = grid[i][j];
            
            
            long long p1 = max_dp[i-1][j] * val; 
            long long p2 = min_dp[i-1][j] * val; 
            long long p3 = max_dp[i][j-1] * val; 
            long long p4 = min_dp[i][j-1] * val; 

            long long max_val = p1;
            if (p2 > max_val) max_val = p2;
            if (p3 > max_val) max_val = p3;
            if (p4 > max_val) max_val = p4;
            long long min_val = p1;
            if (p2 < min_val) min_val = p2;
            if (p3 < min_val) min_val = p3;
            if (p4 < min_val) min_val = p4;

            max_dp[i][j] = max_val;
            min_dp[i][j] = min_val;
        }
    }
    long long ans = max_dp[m-1][n-1];
    if (ans < 0) {
        return -1;
    }
    return ans % MOD;
}