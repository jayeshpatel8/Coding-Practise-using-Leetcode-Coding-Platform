class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int M =grid.size() , N = grid[0].size();
        for ( int i =0; i<M; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == 2) 
                    q.push({i,j});
            }
        }
        int dir[] = {0,1,0,-1,0}, cnt = 0;
        
        while(!q.empty()){
            int sz =  q.size();
            while(sz--){                
                auto [i , j] = q.front(); q.pop();
                
                for ( int d = 0; d < 4; d++){
                    int r = i + dir[d], c = j  + dir[d+1];
                    if (r>=0 && r<M && c>=0 && c<N &&grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                    }
                }
            }           
            cnt += !q.empty();
        }
        for ( int i =0; i<M; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] ==1) 
                    return -1;
            }
        }
        return cnt;
    }
};