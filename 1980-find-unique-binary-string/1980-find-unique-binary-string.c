char* findDifferentBinaryString(char** nums, int numsSize) {
    char* ans = (char*) malloc (sizeof(char)*numsSize+1);
    int total = 1 << numsSize;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i][i] == '0') ans[i] = '1';
        else ans[i] = '0';
    }
    ans[i] = '\0';
    return ans;
}