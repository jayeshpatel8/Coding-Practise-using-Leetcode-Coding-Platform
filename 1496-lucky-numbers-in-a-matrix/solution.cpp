class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>  ans;
        for (int i=0, N=matrix.size(); i<N; i++){
            int min_ = *min_element(begin(matrix[i]), end(matrix[i]));
        
            
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] != min_) continue;
                    int max_= min_;
                for (int r= 0; r <N; r++){
                    if (matrix[r][j] > max_){
                        max_=matrix[r][j];break;
                    }
                }
                if (min_ == max_) ans.push_back(max_);
            }
        }
        return ans;
    }
};
