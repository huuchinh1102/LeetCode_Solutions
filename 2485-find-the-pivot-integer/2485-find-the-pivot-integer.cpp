class Solution {
public:
    int pivotInteger(int n) {
        //2x^2 = n(n+1)
        int a = n*(n+1)/2;
        int x = sqrt(a);
        if (x*x == a) return x;
        return -1; 
    }
};