int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize-1;
    int maxx = 0;
    while (left < right) {
        int water = min(height[left], height[right])*(right-left);
        maxx = max(maxx, water);
        if (height[left] < height[right]) {
            left++;
        }
        else right--;
    }
    return maxx;
}