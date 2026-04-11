class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        const long long MOD = 1000000007LL;
        
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        auto get_group = [](int c1, int c0) {
            if (c0 == 0) return 1;  
            if (c1 == 0) return 3;  
            return 2;             
        };

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            int c1_i = nums1[i], c0_i = nums0[i];
            int c1_j = nums1[j], c0_j = nums0[j];
            int g_i = get_group(c1_i, c0_i);
            int g_j = get_group(c1_j, c0_j);

            if (g_i != g_j) return g_i < g_j;

            if (g_i == 2) {
                if (c1_i != c1_j) return c1_i > c1_j;
                if (c0_i != c0_j) return c0_i < c0_j;
            }

            return false;
        });
        
        long long ans = 0;

        for (int i : idx) {
            int c1 = nums1[i];
            int c0 = nums0[i];
            
            long long p_c1 = power(2, c1);
            ans = (ans * p_c1) % MOD;
            ans = (ans + p_c1 - 1 + MOD) % MOD;

            long long p_c0 = power(2, c0);
            ans = (ans * p_c0) % MOD;
        }

        return ans;
    }
};