bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int ok = 1;
    int rows = matSize;
    int cols = matColSize[0];
    int ** ans1 = (int**) malloc (sizeof(int*)*rows);
    for (int i = 0; i < rows; i++) {
        ans1[i] = (int*) malloc (sizeof(int)*cols);
    }
    int ** ans2 = (int**) malloc (sizeof(int*)*rows);
    for (int i = 0; i < rows; i++) {
        ans2[i] = (int*) malloc (sizeof(int)*cols);
    }
    int ** ans3 = (int**) malloc (sizeof(int*)*rows);
    for (int i = 0; i < rows; i++) {
        ans3[i] = (int*) malloc (sizeof(int)*cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans1[j][rows-i-1] = mat[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans2[j][rows-i-1] = ans1[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans3[j][rows-i-1] = ans2[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (target[i][j] != ans1[i][j]) {
                ok = 0;
                break;
            }
        }
    }
    if (ok == 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (target[i][j] != ans2[i][j]) {
                    ok = -1;
                    break;
                }
            }
        }
    }
    if (ok == -1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (target[i][j] != ans3[i][j]) {
                    ok = -2;
                    break;
                }
            }
        }
    }
    if (ok == -2) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (target[i][j] != mat[i][j]) {
                    ok = -3;
                    break;
                }
            }
        }
    }
    if (ok == -3) return false;
    else return true;
}