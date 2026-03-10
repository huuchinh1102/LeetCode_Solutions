/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}
 
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int i = low-1;
        int j = low;
        int pivot = a[high];
        while (j < high) {
            if (a[j] < pivot) {
                i++;
                swap(&a[j], &a[i]);
            }
            j++;
        }
        swap(&a[high], &a[i+1]);
        quickSort(a, low, i);
        quickSort(a, i+2, high);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    quickSort(nums, 0, numsSize-1);
    int capacity = 3000;
    int** result = (int**) malloc (capacity*sizeof(int*));
    *returnColumnSizes = (int*) malloc (capacity*sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i+1;
        int right = numsSize-1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            if (nums[left] + nums[right] + nums[i] == 0) {
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**) realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*) realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                result[*returnSize] = (int*) malloc (sizeof(int)*3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
                continue;
            }
            if (nums[left] + nums[right] + nums[i] < 0) {
                left++;
            }
            if (nums[left] + nums[right] + nums[i] > 0) {
                right--;
            }
        }
    }
    return result;
}