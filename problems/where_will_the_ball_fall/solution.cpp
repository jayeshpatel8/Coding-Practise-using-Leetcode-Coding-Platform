class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int M = grid.size();        
        int N = grid[0].size();
        vector<int> res;
                
        int R=1, L=-1;
        for (int c=0; c <N; c++){
            int i=0, j=c;
            while (true){
                if ( grid[i][j] == R && (j+1<N) && (grid[i][j+1] == R) )
                     j++;
                else if(grid[i][j] == L && (j-1>=0) &&  (grid[i][j-1] == L) )
                     j--;
                else
                {   res.push_back(-1); break;}
                i++;
                if (i==M) {res.push_back(j);break;}
            }
        }
        return res;
        
    }
};