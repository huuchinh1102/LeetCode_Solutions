class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res;
        if (costBoth >= cost1 + cost2) {
            res = (long long)need1*cost1 + (long long)need2*cost2;
        }
        else if (costBoth <= cost1 && costBoth <= cost2) {
            res = costBoth*max((long long)need1, (long long)need2);
        }
        else if (costBoth <= cost1) {
            if (need1 >= need2) {
                res = (long long)costBoth*need1;
            }
            else {
                res = (long long)costBoth*need1 + (long long)(need2 - need1)*cost2;
            }
        }
        else if (costBoth <= cost2) {
            if (need2 >= need1) {
                res = (long long)costBoth*need2;
            }
            else {
                res = (long long)costBoth*need2 + (long long)(need1 - need2)*cost1;
            }
        }
        else {
            if (need1 >= need2) {
                res = (long long)costBoth*need2 +(long long)(need1 - need2)*cost1;
            }
            else res = (long long)costBoth*need1 + (long long) (need2 - need1)*cost2;
        }
        return res;
    }
};