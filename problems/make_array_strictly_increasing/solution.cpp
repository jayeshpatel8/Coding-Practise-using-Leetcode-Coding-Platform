class Solution {
public:
    int dp[2001][2001] ={};
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int ans = mai(arr1,arr2,0,0,-1);
        return ans >=2001 ? -1 : ans;
    }
    int mai(vector<int>& arr1, vector<int>& arr2, int i , int j, int prev){
        if (i>=arr1.size()) return 0;
         j = upper_bound(begin(arr2)+j,end(arr2),prev) - begin(arr2);
        if (prev >= arr1[i] && j>=arr2.size()) return 2001;
        if (dp[i][j]) return dp[i][j];
        dp[i][j] =  (j>=arr2.size() ? 2001 : 1 + mai(arr1,arr2,i+1,j,arr2[j]));
        if (prev < arr1[i]) dp[i][j] =  min(dp[i][j] ,mai(arr1,arr2,i+1,j,arr1[i]));
        
        return dp[i][j];
    }
};