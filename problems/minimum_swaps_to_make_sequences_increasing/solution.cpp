class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap = 1, noswap = 0 , prev_swap , prev_noswap;      
        for ( int i=1; i<A.size(); i++){
            prev_swap = swap, prev_noswap = noswap, swap = noswap = INT_MAX; 
            
            if (A[i]>A[i-1] && B[i]>B[i-1]){
                noswap =   prev_noswap;
                swap = 1 + prev_swap;
            }
            
            if (A[i]>B[i-1] && B[i]>A[i-1]){
                noswap =   min(noswap, prev_swap);
                swap = min(swap, 1 + prev_noswap);
            }                     
        }

        return min(swap,noswap);
    }    
/*
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size(), dp[N][2];
        dp[0][0]=0, dp[0][1] = 1;      
        for ( int i=1; i<N; i++){
            dp[i][0] = dp[i][1] = INT_MAX;      
            
            if (A[i]>A[i-1] && B[i]>B[i-1]){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = 1 + dp[i-1][1];
            }
            
            if (A[i]>B[i-1] && B[i]>A[i-1]){
                dp[i][0] = min(dp[i][0], dp[i-1][1]);
                dp[i][1] = min(dp[i][1], 1 + dp[i-1][0]);
            }                     
        }

        return min(dp[N-1][0],dp[N-1][1]);
    }
*/    
/*    // Memo
    int dp[100001][2];
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return minSwap(nums1, nums2,0,-1,-1,0);
    }
    int minSwap(vector<int>& A, vector<int>& B, int i, int pA, int pB, int swap){
        if (i == A.size()) return 0;
        if (dp[i][swap] != -1) return dp[i][swap];
        int m =1e5;
        if (A[i]>pA && B[i] >pB){
            m = minSwap(A,B,i+1, A[i],B[i],0);
        }
        if (A[i]>pB && B[i] >pA)
            m = min(m, 1 + minSwap(A,B,i+1, B[i],A[i],1));
        return dp[i][swap] = m;
    }
    */
};