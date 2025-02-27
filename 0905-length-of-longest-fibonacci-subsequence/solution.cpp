class Solution {
public:
    int dp[1001][1001];
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int mlen=0,n = arr.size();
        //vector<vector<int>> dp(n, vector<int>(n));
        
        unordered_map<int,int> map;
        for (int i=n-1; i>=0; i--){
            int x = arr[i];
            map[x]=i;
            for (int j = i+1; j<n-1; j++){
                int y = x + arr[j];
                if(y>arr[n-1])break;
                if (map.count( y)){
                    dp[i][j] = max(dp[i][j],1 + dp[j][map[y]]);
                    mlen = max(mlen, dp[i][j]);
                }
                
            }   
        }
        return mlen ? 2 + mlen : 0;
    }
};
