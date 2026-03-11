int numSpecial(int** mat, int matSize, int* matColSize) {
    int rows = matSize;
    int cols = matColSize[0];
    int res = 0;
    int x;
    for (int i = 0; i < rows; i++) {
        int cnt = 0;
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
                cnt++;
                x = j;
            }
            if (cnt == 2) break;
        }
        if (cnt == 1) {
            int dem = 0;
            for (int a = 0; a < rows; a++) {
                if (mat[a][x] == 1) {
                    dem++;
                }
                if (dem == 2) break;
            }
            if (dem == 1) res++;
        }
    }
    return res;
}