class Solution {
public:
    
    //long long dp[100001]={};
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {    
        sort(begin(rides), end(rides));
        int N = rides.size();
        vector<long long> dp(N + 1, 0);
        
        vector<int> start(N);
        for (int i=0; i<N; i++) start[i]=rides[i][0];
        
        for (int i = N-1; i>=0; i--){
            int next = lower_bound(begin(start),end(start), rides[i][1])-begin(start);
            dp[i] = max(dp[i+1], rides[i][1] - rides[i][0] + rides[i][2] + dp[next]);
        }
        return dp[0];
    }
/*    
    long long dp[100001]={};
    vector<pair<int,int>> g[100001];
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        //sort(begin(rides), end(rides));
        for ( auto &i : rides)            
        {
                g[i[0]].push_back({i[1],i[1]+i[2]-i[0]});
        }
    
        long long ans = 0,   mm=0;
        for ( int i=1; i<=n; i++){
            dp[i]=max(dp[i],dp[i-1]);
            for ( auto j : g[i]){
                dp[j.first] = max<long long>(dp[j.first],  dp[i]+ j.second);                
            }

        }
              
        return dp[n];
    }
*/
};