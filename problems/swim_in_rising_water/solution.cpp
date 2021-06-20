class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({grid[0][0],0});
        int M = grid.size(), N = grid[0].size();
        int end = grid[M-1][N-1],ans=0;
        int dp[M][N];
        memset(dp,1,sizeof(dp));
        dp[0][0]=0;
        int r[4]={1,-1,0,0};
        int c[4]={0,0,1,-1};
        while(!pq.empty()){
          auto [n , n1] = pq.top();
            int  i = n1/M, j = n1%N;
            ans  = max(ans,n);

            if (n == end) return ans;
            
            pq.pop();
            for (int k=0; k<4; k++){
                int r1=i+ r[k],c1=j+c[k];
                if (r1>=0 && r1<M && c1>=0 && c1<N && dp[r1][c1])
                    pq.push({grid[r1][c1],r1*M+c1}),dp[r1][c1]=0;
                    
            }
        }
        return end;
    }
};