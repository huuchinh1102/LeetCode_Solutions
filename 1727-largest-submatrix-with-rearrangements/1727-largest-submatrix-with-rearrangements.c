int compare (const void *a, const void *b) {
    if (*(int*)a > *(int*)b) return -1;
    if (*(int*)a < *(int*)b) return 1;
    return 0;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int res = 0;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) 
            matrix[i][j] += matrix[i-1][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        qsort(matrix[i], cols, sizeof(int), compare);
        for (int j = 0; j < cols; j++) {
            res = max((matrix[i][j])*(j+1), res);
        }
    }
    return res;
}