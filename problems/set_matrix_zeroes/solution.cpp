class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<int> col(N), row(M);
        
        for (int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                if (matrix[i][j]==0)
                    col[j]=row[i]=1;
        for (int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                if (col[j] || row[i])
                    matrix[i][j]=0;
        return ;
    }
};