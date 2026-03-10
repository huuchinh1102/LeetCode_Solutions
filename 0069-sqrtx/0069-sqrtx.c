int mySqrt(int x) {
    if (x == 0) return 0;
    else {
        int left = 1;
        int right = x;
        int mid, res;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (mid <= x/mid) {
                res = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return res;
    }
}