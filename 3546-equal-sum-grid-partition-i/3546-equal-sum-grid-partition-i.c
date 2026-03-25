bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    long long totalSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalSum += grid[i][j];
        }
    }
    if (totalSum % 2 != 0) {
        return false;
    }
    
    long long target = totalSum / 2;

    long long currentSum = 0;
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            currentSum += grid[i][j];
        }
        if (currentSum == target) {
            return true;
        }
    }

    currentSum = 0;
    for (int j = 0; j < cols - 1; j++) {
        for (int i = 0; i < rows; i++) {
            currentSum += grid[i][j];
        }
        if (currentSum == target) {
            return true;
        }
    }

    return false;
}