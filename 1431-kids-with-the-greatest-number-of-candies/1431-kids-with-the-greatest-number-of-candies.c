/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;
    int plus[10005];
    *returnSize = candiesSize;
    bool * res  = (bool*) malloc(sizeof(bool)*candiesSize);
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] >= max) {
            max = candies[i];
        }
    }
    for (int i = 0; i < candiesSize; i++) {
        plus[i] = candies[i] + extraCandies;
    }
    for (int i = 0; i < candiesSize; i++) {
        if (plus[i] >= max) {
            res[i] = true; 
        }
        else {
            res[i] = false;
        }
    }
    return res;
}