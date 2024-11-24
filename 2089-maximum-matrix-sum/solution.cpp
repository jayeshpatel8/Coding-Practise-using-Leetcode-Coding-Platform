class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        size_t mmin = INT_MAX, sum=0, neg=0;
        for (auto i : matrix)
            for (auto j : i){
                if (j < 0)
                    j = -j, neg++;
                mmin = min<size_t>(mmin, j);
                sum +=j;                
            }

        return sum - (neg & 1 ? (mmin + mmin):0) ;
    }
};
