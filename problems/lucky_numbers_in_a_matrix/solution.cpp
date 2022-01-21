class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int M = matrix.size(), N = matrix[0].size();
        for ( int i=0; i<M; i++){
            int min_ = *min_element(begin(matrix[i]),end(matrix[i]));
            for ( int j=0; j<N; j++){
                if (matrix[i][j] == min_){
                    int max_ = INT_MIN,f =1;
                    for ( int i1=0; i1<M; i1++){
                        max_ = max(max_, matrix[i1][j]);
                        if (max_ > min_) {
                         f=0; break;   
                        }
                    }
                    if(f) ans.push_back(min_);
                }
            }
        }
        return ans;
    }
};