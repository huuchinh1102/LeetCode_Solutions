class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long count = 0;
        const int modulo = 1000000007;
        long long sum = 0;
        int even_count = 1;
        int odd_count = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum % 2 == 1) {
                odd_count++;
                count += even_count;
            }
            else {
                even_count++;
                count += odd_count;
            }
        }
        count = (count) % modulo;
        return count;
    }
};