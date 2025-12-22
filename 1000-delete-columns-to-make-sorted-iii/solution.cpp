class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> dp(n,1);
        for (int i=n-2; i>=0; i--){
            for (int j=i+1; j<n; j++){
                int k=0;
                for (; k<strs.size(); k++)
                    if (strs[k][i]> strs[k][j]) break;
                if (k==strs.size()) 
                    dp[i] = max(dp[i],1 +dp[j]);
            }
        }
        int kept = *max_element(begin(dp),end(dp));        
        return n - kept;
    }
};
