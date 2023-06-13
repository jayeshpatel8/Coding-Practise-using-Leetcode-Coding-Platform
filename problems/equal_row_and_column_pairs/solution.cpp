class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int N= grid.size(), ans = 0;
        unordered_map<int,vector<int>> m;
        for (int c=0; c<N; c++) m[grid[0][c]].push_back(c);
        for (int r=0; r<N; r++){            
            for (auto c : m[grid[r][0]]){
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