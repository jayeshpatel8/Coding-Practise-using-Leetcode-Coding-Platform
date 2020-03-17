class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     int m= matrix.size(),n=matrix[0].size();
        bool col0=0;
        for (int i=0; i<m; i++){
            if (0==matrix[i][0])  col0=1;
            for (int j=1; j<n; j++)
                if (0==matrix[i][j]){
                    matrix[i][0]=matrix[0][j] =0;}
        }

        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=1; j--){
                if( 0==matrix[i][0]  || ( 0==matrix[0][j]))
                   matrix[i][j]=0;                                       
            }          
            if(col0)matrix[i][0]=0;      
        }
    }
};