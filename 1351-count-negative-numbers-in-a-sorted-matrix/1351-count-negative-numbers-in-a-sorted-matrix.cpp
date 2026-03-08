class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        int c = 0;
        int r = rows-1;
        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                res += cols - c;
                r--;
            }
            else {
                c++;
            }
        }
        return res;
    }
};