class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int  M=grid.size(), N=grid[0].size();
        for (int i=0; i<M;i++){
            vector<int> s;
            for (int r=i,c=0; r<M && c<N; r++,c++ ){
                s.push_back(grid[r][c]);
            }
            sort(begin(s),end(s),greater<int>());
            for (int r=i,c=0,k=0; r<M && c<N; r++,c++ ){
                grid[r][c] = s[k++];
            }
        }
        for (int j=1; j<N;j++){
            vector<int> s;
            for (int r=0,c=j; r<M && c<N; r++,c++ ){
                s.push_back(grid[r][c]);
            }
            sort(begin(s),end(s));
            
            for (int r=0,c=j,k=0; r<M && c<N; r++,c++ ){
                grid[r][c] = s[k++];
            }
        }
        return grid;
    }
};
