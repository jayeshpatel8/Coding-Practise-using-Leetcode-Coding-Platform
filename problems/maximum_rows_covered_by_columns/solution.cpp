class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector<size_t> num;
        int N = matrix[0].size(), zero=0;
        for (auto &i : matrix){
            size_t a = 0;
            for (int j=N-1, c=0; j>=0; j--,c++){
                a = a | ((size_t)i[j] << c);
            }
            if (a==0) zero++;
            else
                num.push_back(a);
        }
        int ans = 0;
        for (size_t i=1; i<(1<<N); i++){
            if (__builtin_popcount(i) > numSelect) continue;
            int c = 0;
            for (auto j : num){
                c += (j & i)==j;
            }
            ans= max(ans,c);
        }

        return ans + zero;
    }
};