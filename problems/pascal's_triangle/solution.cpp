class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for (int i=1; i<numRows; i++){            
            for (int j=0; j<=i; j++){
                int n  =  (j-1 >=0 ? ans[i-1][j-1] : 0) +  (j <= i-1 ? ans[i-1][j] : 0) ;
                ans[i].push_back(n);
            }
        }
        return ans;
    }
};