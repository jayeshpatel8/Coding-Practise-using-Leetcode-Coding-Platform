class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int,int> bits;
        int  N =  grid[0].size(), M= grid.size();
        for (auto r=0; r<M; r++){   
            int bit=0;
            for (auto i=0; i<N; i++)
                if (grid[r][i])
                    bit |= 1<<i;
            if (!bit) return {r};
            bits[bit]=r;            
        }
        
        for (auto [b1,r1] : bits)
            for (auto [b2,r2] : bits)
                if (b1 & b2) continue;
                else {
                    if (r1  < r2) return {r1,r2};
                    else return {r2,r1};
                }
        return {};
    }
};