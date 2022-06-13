class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int N = t.size();
        for (int i=1; i<N; i++){            
            t[i][0] += t[i-1][0];
            for (int j=1; j<i; j++)
                t[i][j] += min(t[i-1][j],t[i-1][j-1]);
            t[i][i] += t[i-1][i-1];
        }
        return *min_element(begin(t[N-1]),end(t[N-1]));
    }
};