class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int r=0,c=N-1;
        while (r < M && c >=0 ){
            int cur = matrix[r][c];
            if (target < cur) c--;
            else if (target > cur) r++;
            else
                return true;
        }
        return false;
    }
};