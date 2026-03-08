class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size()-1;
        int mid = (right-left)/2;
        int ok = 0;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (letters[mid] <= target) {
                left = mid +1;
            }
            else {
                right = mid -1;
                ok = 1;
            }
        }
        if (ok == 1) {
            return letters[left];
        }
        else return letters[0];
    }
};