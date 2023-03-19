class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int N  =  grid.size() * grid.size();
        unordered_map<int, array<int,2>> m;
        for (int i = 0; i< grid.size(); i++){
            for (int j=0; j<grid.size(); j++){
                m[grid[i][j]]={i,j};
            }
        }
        for (int i=0,r=0,c=0; i<N-1; i++){
            auto j = m[i+1];
            int cd = abs(r-j[0]), rd = abs(c-j[1]);
            if (cd + rd !=3) return false;
            r= j[0],c=j[1];
        }
        return true;
    }
};