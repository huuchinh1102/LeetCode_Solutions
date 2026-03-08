class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int count = intervals.size();
        vector<pair<int,int>> starts;
        int ends[100005];
        int index[100005];
        for (int i = 0; i < count; i++) {
            starts.push_back({intervals[i][0], i});
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        for (int i = 0; i < count; i++) {
            int left = 0;
            int right = count - 1;
            int mid;
            int ok = 0;
            while (left <= right) {
                mid = left + (right-left)/2;
                if (ends[i] == starts[mid].first) {
                    index[i] = starts[mid].second;
                    ok = 2;
                    break;
                }
                else if (ends[i] > starts[mid].first) {
                    left = mid + 1;
                }
                else if (ends[i] < starts[mid].first) {
                    right = mid - 1;
                    ok = 1;
                }
            }
            if (ok == 1) {
                index[i] = starts[left].second;
            }
            else if (ok == 0) index[i] = -1;
        }
        vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(index[i]);
        }
        return result;
    }
};