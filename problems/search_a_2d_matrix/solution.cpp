class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m=matrix.size()-1;        
        if (matrix[0].empty()) return false;
        int n=matrix[0].size()-1;
        
        int row=m,col=n;
        for  ( int i=0; i<= row; )
        {   
            int row_mid = i+(row-i)/2;
            if (target >= matrix[row_mid][0] && target <= matrix[row_mid][n])
            {                
                for  ( int j=0, col=n; j<= col; ){
                    int col_mid = j+(col-j)/2;

                    if (matrix[row_mid][col_mid]==target) return true;
                    if (matrix[row_mid][col_mid]<target)
                        j=col_mid+1;
                    else
                        col=col_mid-1;   
                }
                break;
            }
            else if (target < matrix[row_mid][0])
                row=row_mid-1;
            else
                i=row_mid+1;
        }

        return false;
    }
};