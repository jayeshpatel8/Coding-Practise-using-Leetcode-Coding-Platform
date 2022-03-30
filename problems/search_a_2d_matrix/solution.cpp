class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int i=M-1, j=0;        
        while (i>=0 && j<N){
            if ( matrix[i][j] == target) return true;
            else if ( matrix[i][j] < target)
                j++;            
            else
                i--;
        }
        return false;;
    }
};