bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int rows = matSize;
    int cols = matColSize[0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 == 0) {
                if (mat[i][j] != mat[i][(j + k) % cols]) return false;
            }
            else {
                if (mat[i][j] != mat[i][(j - k % cols + cols) % cols]) return false;
            }
        }
    }
    return true;
}