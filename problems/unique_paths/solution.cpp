class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) swap(m,n);
        long ans = 1;
        for (int i=1, j =n; j<m+n-1; i++,j++){
            ans *= j;
            ans /= i;
        }
        return ans;        
    }
};