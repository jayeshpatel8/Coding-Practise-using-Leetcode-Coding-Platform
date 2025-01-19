class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
        const int M = h.size(), N = h[0].size(),dirs[5] ={-1,0,1,0,-1};;
        vector<vector<bool>> vis(M,vector<bool>(N,0));
        for (int i=0; i<M; i++){
            pq.push({h[i][0], i,0});
            pq.push({h[i][N-1], i,N-1});
            vis[i][0]= vis[i][N-1]=1;
        }
        for (int j=1; j<N-1; j++){
            pq.push({h[0][j], 0,j});
            pq.push({h[M-1][j], (M-1),j});
            vis[0][j]= vis[M-1][j]=1;
        }
        int ans = 0;
        
        while (!pq.empty()){
            auto [hi, i,j] = pq.top(); 
            pq.pop();
            //int i = n/N, j = n%N;
            
            for ( int d = 0; d<4; d++){
                int r=i + dirs[d], c =  j + dirs[d+1] ;
                if (r<0 || c<0 || r>=M || c>=N || vis[r][c] ) continue;
                {
                    ans += max(0,hi - h[r][c]);
                    pq.push({max(hi ,h[r][c]), r,c});
                    vis[r][c]=1;
                }                
            }
  
        }
        return ans;
    }
};
/*
[1,4,3,1,3,2],
[3,2,1,3,2,4],
[2,3,3,2,3,1]
*/
