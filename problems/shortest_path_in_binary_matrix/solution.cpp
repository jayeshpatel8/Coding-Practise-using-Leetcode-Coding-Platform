class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int N= grid.size();
        if (grid[0][0] || grid[N-1][N-1]) return -1;        
        if(N==1) return grid[0][0]==0? 1:-1;
        int row[8]={0,-1,1,0, 1,-1,-1, 1};
        int col[8]={-1,0,0,1, 1, 1,-1,-1};
        queue<pair<int,int>>q;
        q.push({0,0});grid[0][0]=1;
        int cnt=0;
        while(!q.empty()){
            int sz = q.size();
            ++cnt;
            while (sz--){                
                pair<int,int> pq=q.front(); q.pop();                
                const int i = pq.first, j = pq.second;
                for (int k=0; k<8; k++){
                    int r = i+row[k], c = j+col[k];
                    if (r>=0 && c>=0 && r<N && c<N && !grid[r][c]){
                        if(r==N-1 && c==N-1) return ++cnt;
                        {
                            q.push({r,c});
                            grid[r][c]=1;
                        }
                    }
                }
            }
        }
                
        return -1;
        
    }
};