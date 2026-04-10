
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*) malloc (sizeof(int)*numsSize);
    int mark;
    int cnt0 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            cnt0++;
            mark = i;
        }
    }
    if (cnt0 >= 2) {
        for (int i = 0; i < numsSize; i++) {
            res[i] = 0;
        }
    }
    else if (cnt0 == 1) {
        int temp = 1;
        for (int i = 0; i < numsSize; i++) {
            res[i] = 0;
        }
        for (int i = 0; i < numsSize; i++) {
            if (i != mark) {
                temp *= nums[i];
            }
        }
        res[mark] = temp;
    }
    else {
        int temp = 1;
        for (int i = 0; i < numsSize; i++) {
            temp *= nums[i];
        }
        for (int i = 0; i < numsSize; i++) {
            res[i] = temp/nums[i];
        }
    }
    return res;
}