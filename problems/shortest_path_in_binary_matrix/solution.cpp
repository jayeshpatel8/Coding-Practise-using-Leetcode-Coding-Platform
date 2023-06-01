class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {        
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;        
        vector<int> q{0};
        grid[0][0]=true;
        int d=  1;
        int dirs[] = {-1,0,1,0,-1,-1,1,1,-1};
        while (!q.empty()){
            vector<int> t;            
            for (auto u : q){
                int i=u/n, j = u%n;
                if (i==n-1 && j==n-1) return d;
                for (auto d1 = 0; d1<8; d1++){
                    int i1=  i +dirs[d1], j1 = j+ dirs[d1+1]; 
                    if (i1<0 || i1 >=n || j1 < 0 || j1>=n || grid[i1][j1]) continue;
                    grid[i1][j1]=true;
                    t.push_back(i1*n +j1);
                }
            }
             q.swap(t);++d;
        }   
        return -1;
    }
};