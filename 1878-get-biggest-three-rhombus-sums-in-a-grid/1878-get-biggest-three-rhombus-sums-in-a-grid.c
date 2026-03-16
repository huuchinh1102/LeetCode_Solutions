#include <stdlib.h>
void updateTop3(int* top3, int val) {
    if (val == top3[0] || val == top3[1] || val == top3[2]) {
        return;
    }
    if (val > top3[0]) {
        top3[2] = top3[1];
        top3[1] = top3[0];
        top3[0] = val;
    } else if (val > top3[1]) {
        top3[2] = top3[1];
        top3[1] = val;
    } else if (val > top3[2]) {
        top3[2] = val;
    }
}

int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int top3[3] = {0, 0, 0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            updateTop3(top3, grid[i][j]);
            int L = 1;
            while (i + 2 * L < m && j - L >= 0 && j + L < n) {
                int sum = 0;
                int x = i, y = j;
                
                for (int k = 0; k < L; k++) sum += grid[x++][y++];
                
                for (int k = 0; k < L; k++) sum += grid[x++][y--];

                for (int k = 0; k < L; k++) sum += grid[x--][y--];
                
                for (int k = 0; k < L; k++) sum += grid[x--][y++];
                
                updateTop3(top3, sum);
                L++; 
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (top3[i] > 0) count++;
    }

    *returnSize = count;
    int* result = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        result[i] = top3[i];
    }

    return result;
}