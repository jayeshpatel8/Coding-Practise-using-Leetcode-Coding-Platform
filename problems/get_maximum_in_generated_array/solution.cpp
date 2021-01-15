class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<=0) return 0;
        if (n<=1) return 1;
        vector<int> A(n+1);
        A[0]=0;
        A[1]=A[2]=1;
        int m=1;
        for (int i=3; i<=n; i++){
            if (i%2)
                A[i] = A[i/2] + A[i-i/2]; 
            else
                A[i] = A[i/2];
            m = max(m,A[i]);
        }
        return m;
    }
};