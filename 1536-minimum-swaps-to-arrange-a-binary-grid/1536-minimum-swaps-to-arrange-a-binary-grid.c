
int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int needed[205];
    int maxRight[205] = {0};
    int current = gridSize-1;
    int x = 0;
    int res = 0;
    for (int i = 0; i < gridSize-1; i++) {
        needed[i] = current;
        current--;
    }
    for (int i = 0; i < gridSize; i++) {
        int j = gridSize-1;
        while (grid[i][j] == 0 && j >= 1) {
            maxRight[i]++;
            j--;
        }
    }
    for (int i = 0; i < gridSize; i++) {
        if (x == gridSize-1) break;
        else if (maxRight[i] >= needed[x]) {
            res += (i-x);
            int temp = maxRight[i];
            for (int j = i; j >= x+1; j--) {
                maxRight[j] = maxRight[j-1];
            }
            maxRight[x] = temp;
            x++;
            i = x-1;
        }
    }
    if (x == gridSize-1) return res;
    else return -1;
}