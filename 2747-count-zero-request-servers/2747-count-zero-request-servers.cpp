class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> orderedQueries;
        int queryCount = queries.size();
        for (int i = 0; i < queryCount; ++i) {
            orderedQueries.emplace_back(queries[i], i);
        }
        sort(orderedQueries.begin(), orderedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> answer(queryCount);
        int left = 0, right = 0;
        int active = 0;
        int logCount = logs.size();

        for (auto [q, index] : orderedQueries) {
            // Thêm các log có thời điểm <= q.
            while (right < logCount && logs[right][1] <= q) {
                int id = logs[right][0];
                if (++freq[id] == 1) {
                    ++active;
                }
                ++right;
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];
                if (--freq[id] == 0) {
                    --active;
                }
                ++left;
            }
            answer[index] = n - active;
        }
        return answer;
    }
};