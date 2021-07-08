class Solution {
public:
    int maxHeight(vector<vector<int>>& cubs) {
        for (auto &a : cubs){
            if (a[2]<a[1]) swap(a[2],a[1]);
            if (a[2]<a[0]) swap(a[2],a[0]);
            if (a[1]<a[0]) swap(a[1],a[0]);
        }
        sort(begin(cubs),end(cubs),[](auto & a, auto &b){
                    return a[2]!=b[2] ? (a[2]< b[2]) : (a[1]!=b[1]? a[1]<b[1] : a[0]<b[0]);
                });

        int N = cubs.size();
        int dp[N+1],ans=0;
        dp[N]=0; dp[N-1] = cubs[N-1][2];
        for (int i = N-2; i>=0; i--){
            dp[i]=cubs[i][2];
            for (int j=N-1;j>i; j-- ){
                if (cubs[i][0]<=cubs[j][0] && 
                   cubs[i][1]<=cubs[j][1] && 
                   cubs[i][2]<=cubs[j][2] ){
                    dp[i]  = max(dp[i], cubs[i][2]+dp[j]);
                }
            }
            
        }
        return *max_element(dp,dp+N);
    }
};