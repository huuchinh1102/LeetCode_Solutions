class Solution {
    long long total_island = 0;
    int m, n;
    long long dfs_island(vector<vector<int>>& grid, int i, int j) {
        long long current_sum = grid[i][j];
        grid[i][j] = 0;
        if (i-1 >= 0 && grid[i-1][j] > 0) current_sum += dfs_island(grid, i-1, j);
        if (j-1 >= 0 && grid[i][j-1] > 0) current_sum += dfs_island(grid, i, j-1);
        if (i+1 < m && grid[i+1][j] > 0) current_sum += dfs_island(grid, i+1, j);
        if (j+1 < n && grid[i][j+1] > 0) current_sum += dfs_island(grid, i, j+1);
        return current_sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
            for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sumisland = dfs_island(grid, i, j);
                    if (sumisland % k == 0) {
                        total_island++;
                    }
                }
            }
        }
        return total_island;
    }
};