class Solution {
public:
    int M, N, ans = INT_MAX;
    int d [5] = {-1,0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& H) {
        M = H.size(), N = H[0].size();
        priority_queue<pair<int, array<int,2>>> pq;
        pq.push({0,{0,0}});        
        vector<vector<int>> dp(M,vector<int>(N, INT_MAX));
        dp[0][0]=0;
        while (!pq.empty()){
            auto [e , p] = pq.top();
            pq.pop();
            int x = p[0], y = p[1] ,eff = (-1) * e;
            if (x==M-1 && y==N-1) return eff;
            for (int r = 0; r<4; r++){
                int x1 = x +d[r], y1 = y + d[r+1];
                if (x1 <0 || x1 >= M || y1 < 0 || y1 >= N ) continue;
                int e2 = max(abs(H[x][y] - H[x1][y1]),eff);
                
                if (e2  < dp[x1][y1]){
                    dp[x1][y1] = e2;
                    pq.push({(-1) * e2,{x1,y1}});
                }
            }            
        }
        return -1;
    }
};