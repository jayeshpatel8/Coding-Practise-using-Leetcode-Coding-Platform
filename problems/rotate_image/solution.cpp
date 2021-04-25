class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int  m = matrix.size(), n = matrix[0].size();
        int r1=0,r2=m-1,c1=0,c2=n-1;
        for (int i=0; i<m/2; i++){
            for (int i = 0; i<r2-r1; i++)
            {
                int t = matrix[r1][c1 + i];                    
                matrix[r1][c1 + i] = matrix[r2-i][c1];
                matrix[r2-i][c1] = matrix[r2][c2-i];
                matrix[r2][c2-i]  = matrix[r1+i][c2];
                matrix[r1+i][c2] = t;                
            }


            r1++;r2--;c1++;c2--;
        }
    }
};