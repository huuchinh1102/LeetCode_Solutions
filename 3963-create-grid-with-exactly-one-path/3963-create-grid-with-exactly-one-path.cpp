class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        res.push_back(string(n, '.'));
        for (int i = 1; i < m; i++) {
            string row = "";
            for (int j = 0; j <= n - 2; j++) {
                row += '#';
            }
            row += '.';
            res.push_back(row);
        }
        return res;
    }
};