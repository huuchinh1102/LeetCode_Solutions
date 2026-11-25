#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const long long BASE = 911382323;
        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        int n = nums.size();

        vector<long long> hash1(n + 1), hash2(n + 1);
        vector<long long> power1(n + 1, 1), power2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] * BASE + nums[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * BASE + nums[i]) % MOD2;
            power1[i + 1] = power1[i] * BASE % MOD1;
            power2[i + 1] = power2[i] * BASE % MOD2;
        }

        auto check = [&](int len) {
            unordered_map<long long, int> freq;
            freq.reserve(n - len + 1);
            int uniqueCount = 0;

            for (int l = 0; l + len <= n; l++) {
                int r = l + len;

                long long h1 =
                    (hash1[r] - hash1[l] * power1[len] % MOD1 + MOD1) % MOD1;
                long long h2 =
                    (hash2[r] - hash2[l] * power2[len] % MOD2 + MOD2) % MOD2;

                long long key = h1 * MOD2 + h2;

                int count = ++freq[key];
                if (count == 1) {
                    uniqueCount++;
                } else if (count == 2) {
                    uniqueCount--;
                }
            }

            return uniqueCount > 0;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};