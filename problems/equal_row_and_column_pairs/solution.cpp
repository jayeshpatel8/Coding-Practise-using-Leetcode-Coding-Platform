class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int N= grid.size(), ans = 0;

        for (int r=0; r<N; r++){            
            for (int c=0; c<N; c++){
                bool f=true;
                for (int i=0; i<N;i++)
                    if (grid[r][i] != grid[i][c]) {
                        f=false;break;
                    }
                ans +=f;
            }
        }
        return ans;
    }
};