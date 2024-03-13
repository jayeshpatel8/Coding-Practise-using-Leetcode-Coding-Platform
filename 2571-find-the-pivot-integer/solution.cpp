class Solution {
public:
    int pivotInteger(int n) {
        long  sum  = n * (n+1) / 2;
        for (int i=1,j=0; j<=sum; i++){
            j+=i;
            if (j==sum) return i;
            sum-=i;
        }
        return -1;
    }
};
