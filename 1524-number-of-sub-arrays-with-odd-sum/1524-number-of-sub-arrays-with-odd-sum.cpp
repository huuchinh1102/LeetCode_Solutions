class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long count = 0;
        const int modulo = 1000000007;
        vector <int> prefix(arr.size()+1, 0);
        prefix[0] = 0;
        int even_count = 1;
        int odd_count = 0;
        for (int i = 0; i < arr.size(); i++) {
            prefix[i+1] = prefix[i] + arr[i];
            if (prefix[i+1] % 2 == 1) {
                odd_count++;
                count = (count + even_count) % modulo;
            }
            else {
                even_count++;
                count = (count + odd_count) % modulo;
            }
        }
        return count;
    }
};