class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // dp[i][j] = max(dp[i-1][k] + A[i][j] - abs(j-k)) for k=0 to n
        int m = points.size(), n = points[0].size();
        vector<long long> cur(n), prev(n); 
        for (auto & r : points){
            for (long long j =0, max_sum = 0; j<n; j++){
                max_sum = max( max_sum - 1, prev[j]);
                cur[j] = max_sum;
            }
        
            for (long long j =n-1, max_sum = 0; j>=0; j--){
                    max_sum = max( max_sum - 1, prev[j]);
                    cur[j] = max(cur[j], max_sum) + r[j];
            }
            prev.swap(cur);
        }
        return *max_element(begin(prev),end(prev));
    }
};
