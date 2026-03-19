#include <stdlib.h>

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int count = 0;
    int* dpX = (int*)calloc(cols, sizeof(int));
    int* dpY = (int*)calloc(cols, sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        int rowX = 0;
        int rowY = 0;
        
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'X') {
                rowX++;
            } else if (grid[i][j] == 'Y') {
                rowY++;
            }

            dpX[j] += rowX;
            dpY[j] += rowY;

            if (dpX[j] > 0 && dpX[j] == dpY[j]) {
                count++;
            }
        }
    }

    free(dpX);
    free(dpY);
    
    return count;
}