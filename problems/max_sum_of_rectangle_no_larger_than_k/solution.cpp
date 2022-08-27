class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
        
        for (int col =0; col <cols; col++){
            vector<int> sums(rows);
            for (int c = col; c<cols; c++){
                for (int r=0; r<rows; r++){
                    sums[r] += matrix[r][c];
                }
                set<int> set={0};
                int csum = 0;
                for (auto sum : sums){
                    csum += sum;
                    auto it = set.lower_bound(csum - k);
                    if (it != set.end()){
                        ans = max(ans , csum - *it);
                    }
                    set.insert(csum);
                }
            }
        }
        return ans;
    }
};