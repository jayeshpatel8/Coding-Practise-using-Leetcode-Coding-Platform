class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long psum [2][n+1];
        psum[0][0] = psum[1][0] = 0;
        
        for (int i=0; i<n; i++){
            psum[0][i+1] =  psum[0][i] + grid[0][i];
            psum[1][i+1] =  psum[1][i] + grid[1][i];
        }
        
        long long sum1=0,ans = LONG_MAX;
        for ( int i=0; i<n; i++){
           // int sum  = psum[0][i+1] +  psum[1][n] - psum[1][i];

                long long ans1 = max({psum[1][i], psum[0][n]-psum[0][i+1]});
                if (ans1 < ans) ans = ans1;

        }

        return ans;
    }
};