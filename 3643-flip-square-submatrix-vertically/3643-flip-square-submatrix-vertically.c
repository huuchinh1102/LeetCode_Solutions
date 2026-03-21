/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    int rows = gridSize;
    int cols = gridColSize[0];
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }
    for (int i = x; i <= x + (k-1)/2; i++) {
        for (int j = y; j < k+y; j++) {
            int temp = grid[i][j];
            grid[i][j] = grid[x+k-1-i+x][j];
            grid[x+k-1-i+x][j] = temp;
        }
    }  
    return grid;  
}