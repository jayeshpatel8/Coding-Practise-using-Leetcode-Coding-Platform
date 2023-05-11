class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) { 
        int N= nums1.size(), M = nums2.size();
        vector<vector<int>> lcs(N+1,vector<int>(M+1));
        for (int i=1; i<=N; i++){
            for (int j=1; j<=M; j++){
                if (nums1[i-1]==nums2[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
            }
        }
        return lcs[N][M];
    }
};