class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N =  matrix[0].size(),i=0,j=N-1;
        while ( j>=0 && i<M ){
            auto n = matrix[i][j];
             
             if (target > n)i++;
             else if ( target < n) j--;
             else return true;
        }
        return false;
    }
};