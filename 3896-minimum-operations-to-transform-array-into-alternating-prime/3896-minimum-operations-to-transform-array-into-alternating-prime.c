int prime (int num) {
    if (num == 1) return -1; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return -1;
    }
    return 1;
}

int minOperations(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i = i+2) {
        int check = prime(nums[i]);
        if (check == 1) continue;
        else {
            while (check != 1) {
                nums[i]++;
                res++;
                check = prime(nums[i]);
            }
        }
    }
    for (int i = 1; i < numsSize; i = i+2) {
        int check = prime(nums[i]);
        if (check == -1) continue;
        else {
            while (check == 1) {
                nums[i]++;
                res++;
                check = prime(nums[i]);
            }
        }
    }
    return res;
}