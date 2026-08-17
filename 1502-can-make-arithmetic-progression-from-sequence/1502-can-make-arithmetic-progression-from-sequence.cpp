class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int hieu = arr[1] - arr[0];
        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i+1] - arr[i] != hieu) return false;
        }
        return true;
    }
};