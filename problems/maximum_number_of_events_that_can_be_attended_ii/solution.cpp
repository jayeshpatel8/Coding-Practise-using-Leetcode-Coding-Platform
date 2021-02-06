
class Solution {
public:
    int n, K;
    static bool compare(const vector<int> & a, const vector<int> & b){
        return ( a[1] < b[1]);
    }
   
    vector<vector<int>> dp;
    int maxValue(vector<vector<int>>& e, int k) {
        sort(e.begin(), e.end(), compare);
        
         n= e.size(); K=k;
        dp = vector<vector<int>>(n+2, vector<int>(k + 1));
        
        for (int i=0; i<n; i++){
            auto idx = lower_bound(rbegin(e) -(n- i) , rend(e),e[i],
                   [](const vector<int>& vt , const vector<int>& v){return vt[1]>= v[0];}) - rbegin(e);

    
            for (int K=1; K<=k; K++){
                dp[i+1][K] = max(e[i][2] +dp[n-idx][K-1], dp[i][K]);
                            
            }
        }

        return dp[n][k];
    }
    int maxV(vector<vector<int>>& e, int k, int i){
        if (i>=n || k==0) return 0;
        if (dp[i][k] != -1) 
        return dp[i][k];
        
        
        auto idx = upper_bound(begin(e) + i, end(e),e[i][1],
                   [](int t , const vector<int>& v){return v[0]>t;}) - begin(e);               
        return *std::max_element(dp[n].begin(), dp[n].end());
    }
};
