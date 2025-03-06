class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), num=0, sum=0;

        vector<bool> v(n*n+1);
        for (auto i : grid)
            for (auto j : i){
                if (v[j]){
                    num = j;
                }
                v[j]=true;
                sum+=j;
            }
        return {num, n*n*(n*n+1)/2 - (sum - num)};
    }
};
