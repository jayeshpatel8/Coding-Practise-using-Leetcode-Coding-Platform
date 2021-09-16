class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int n = (M+1)/2;
        vector<int> ans;
        int r1=0,r2=M-1,c1=0,c2=N-1;
        while (r1<=r2 && c1<=c2){
            for (int j=c1 ; j<=c2; j++)
                ans.push_back(matrix[r1][j]);

            for (int r=r1+1,c = c2; r<r2 ; r++)
                ans.push_back(matrix[r][c]);
            
            if (r2>r1)
                for (int c=c2, r= r2; c>=c1 ; c--)
                    ans.push_back(matrix[r][c]);            
            if (c1<c2)
                for (int c=c1, r= r2-1; r>r1 ; r--)
                    ans.push_back(matrix[r][c]);         
            r1++,r2--,c1++,c2--;
        }
        return ans;
    }
};