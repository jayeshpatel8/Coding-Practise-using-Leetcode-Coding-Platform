class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int  M = matrix.size(), N = matrix[0].size(), col0=0;
        
        for (int r = 0; r < M; r++){
            if(!matrix[r][0]) col0=1;
            for (int c = 1; c <N; c++){
                if(!matrix[r][c])
                    matrix[r][0] = matrix[0][c] = 0; 
            }
        }
        for (int r = M-1; r >=0 ; r--){            
            for (int c = N-1; c >=1; c--){
                if(!matrix[r][0] || !matrix[0][c])
                    matrix[r][c] = 0; 
            }
            if(col0) matrix[r][0]=0;
        }        
    }
};