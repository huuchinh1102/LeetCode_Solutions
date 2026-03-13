#include <math.h>

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    long long minn = 1000001;
    for (int i = 0; i < workerTimesSize; i++) {
        if (workerTimes[i] < minn) {
            minn = workerTimes[i];
        }
    }
    
    long long left = 1;
    long long right = minn * (long long)mountainHeight * (mountainHeight + 1) / 2;
    long long potential = right;
    
    while (left <= right) {
        long long reduce = 0;
        long long mid = left + (right - left) / 2;
        
        for (int i = 0; i < workerTimesSize; i++) {
            long long k = (long long)((-1.0 + sqrt(1.0 + 8.0 * (double)mid / workerTimes[i])) / 2.0);
            reduce += k;
        }
        
        if (reduce >= mountainHeight) {
            potential = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return potential;
}