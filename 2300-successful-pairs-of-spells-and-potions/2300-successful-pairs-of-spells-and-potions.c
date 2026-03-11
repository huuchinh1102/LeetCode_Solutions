/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare (const void *a, const void *b) {
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int * ans = (int*) malloc (sizeof(int)*spellsSize);
    *returnSize = spellsSize;
    qsort(potions, potionsSize, sizeof(int), compare);
    for (int i = 0; i < spellsSize; i++) {
        long long target = success/spells[i];
        if (success % spells[i] != 0) target++;
        long long left = 0;
        long long right = potionsSize-1;
        long long mid;
        int valid = potionsSize;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (potions[mid] < target) {
                left = mid+1;
            }
            else {
                valid = mid;
                right = mid - 1;
            }
        }
        ans[i] = potionsSize-valid;
    }
    return ans;
}