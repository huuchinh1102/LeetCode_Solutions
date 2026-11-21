class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int right = n - 1;
        long long cost = 0;
        long long answer = 0;
        deque<pair<int, int>> groups;

        for (int left = n - 1; left >= 0; --left) {
            int value = nums[left];
            int count = 1;

            while (!groups.empty() && groups.front().first <= value) {
                int groupValue = groups.front().first;
                int groupCount = groups.front().second;
                groups.pop_front();

                cost += 1LL * (value - groupValue) * groupCount;
                count += groupCount;
            }

            groups.push_front({value, count});

            while (cost > k) {
                cost -= groups.back().first - nums[right];
                --groups.back().second;
                --right;

                if (groups.back().second == 0) {
                    groups.pop_back();
                }
            }

            answer += right - left + 1;
        }

        return answer;
    }
};