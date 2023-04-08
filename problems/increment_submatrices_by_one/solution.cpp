class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n));
        for (auto &q : queries){
             ans[q[0]][q[1]]++;
            if ((q[2]+1 < n) && (q[3]+1 < n)){
                ans[q[2]+1][q[3]+1]++;
            }
            if ((q[3]+1 < n)){
                ans[q[0]][q[3]+1]--;
            }
            if ((q[2]+1 < n)){
                ans[q[2]+1][q[1]]--;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=1; j<n; j++){                
                ans[i][j] += ans[i][j-1];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=1; j<n; j++){                
                ans[j][i] += ans[j-1][i];
            }
        }
        return ans;
    }
    vector<vector<int>> rangeAddQueries2(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n));
        for (auto &q : queries){
            for (int r=q[0]; r<=q[2]; r++){
                ans[r][q[1]]++;
                if (q[3]+1 < n)
                    ans[r][q[3]+1]--;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0,psum=0; j<n; j++){
                psum += ans[i][j];
                ans[i][j] = psum;
            }
        }
        return ans;
    }
};