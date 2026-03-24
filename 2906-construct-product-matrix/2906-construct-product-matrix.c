/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int rows = gridSize;
    int cols = gridColSize[0];
    *returnSize = rows;
    *returnColumnSizes = (int*) malloc (sizeof(int)*rows);
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }
    int ** ans = (int**) malloc (sizeof(int*)* rows);
    for (int i = 0; i < rows; i++) {
        ans[i] = (int*) malloc (sizeof(int)* cols);
    }

    long long pref = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans[i][j] = pref;
            pref = (pref * grid[i][j]) % 12345;
        }
    }
    long long suff = 1;
    for (int i = rows-1; i >= 0; i--) {
        for (int j = cols-1; j >= 0; j--) {
            ans[i][j] = (suff * ans[i][j]) % 12345;
            suff = (suff * grid[i][j]) % 12345;
        }
    }
    return ans;
}