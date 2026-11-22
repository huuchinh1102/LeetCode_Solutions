class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == 'a') {
            i++;
        }
        if (i == n) return true;
        else if (s[i] == 'b') {
            while (i < n) {
                if (s[i] == 'a') return false;
                else i++;
            }
            return true;
        }
        return true;
    }
};