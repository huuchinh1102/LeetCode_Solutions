#include <stdbool.h>
bool canEatAll(int* piles, int pilesSize, int h, int k) {
    long long total_hours = 0;
    
    for (int i = 0; i < pilesSize; i++) {
        total_hours += (piles[i] + k - 1LL) / k; 
    }
    
    return total_hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }
    
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canEatAll(piles, pilesSize, h, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}