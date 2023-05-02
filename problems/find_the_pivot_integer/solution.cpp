class Solution {
public:
    int pivotInteger(int n) {
        for (int i=n,k = (n * (n+1))/2, j= n; i>0; i--){
            if (k == j) return i;
            j+=i-1;
            k-=i;
        }
        return -1;
    }
};