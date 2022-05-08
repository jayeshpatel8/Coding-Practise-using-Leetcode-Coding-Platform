class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        queue<array<int,4>> pq;
        if (grid[0][0] ==')') return false;
        int m = grid.size(), n = grid[0].size();
        pq.push({1,0,0,m+n-2});
        int tot = m+n-1;
        int vis [101][101][201]={};
        
        while (!pq.empty()){
            auto v = pq.front(); pq.pop();
            int cnt = v[0];
            int r  = v[1],c=v[2];
                if (cnt == 0 && r==m-1 && c==n-1){
                    return true;
                }   
            int i= r+1,j=c+1;
            if (i <m ){
                
                 auto c1 = cnt + (grid[i][c] =='(' ? 1 : -1);
                
                if (c1>=0 && !vis[i][c][c1]) pq.push({c1,i,c,v[3]-1}), vis[i][c][c1]=1;
                
            }
            if (j <n ){
                
                auto c2 = cnt + (grid[r][j] =='(' ? 1 : -1);

                if (c2>=0 && !vis[r][j][c2]) pq.push({c2,r,j,v[3]-1}) , vis[r][j][c2]=1;
                
            }
            
        }
        return false;
    }
};