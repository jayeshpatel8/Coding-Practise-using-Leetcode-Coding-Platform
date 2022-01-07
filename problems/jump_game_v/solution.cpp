class Solution {
public:
    int dp[1001]={};
    int maxJumps(vector<int>& arr, int d) {
        int ans=1;
        for (int i=0; i<arr.size(); i++)
            ans = max(ans, dfs(arr,d,i));
        return ans;
    }    
    int dfs(vector<int>& arr,int d, int i){
        if (dp[i]) return dp[i];
        int ans=1;
        for (int j=i+1, n = min<int>(i+d,arr.size()-1); j<=n && arr[i] > arr[j]; j++)
            ans = max(ans, 1 + dfs(arr,d,j));
        for (int j=i-1,n =max(0,i-d); j >= n && arr[i] > arr[j]; j--)
            ans = max(ans, 1 + dfs(arr,d,j));
        return dp[i] = ans;
    }
};