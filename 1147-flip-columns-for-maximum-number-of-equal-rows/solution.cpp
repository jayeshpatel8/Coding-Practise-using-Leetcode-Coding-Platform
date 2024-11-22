class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> f;
        for (auto & r : matrix){
            string s;
            for (int c=0; c<r.size(); c++){
                if (r[0] == r[c]) s +='T';
                else s +='F';
            }
            f[s]++;
        }
        int ans = 0;
        for ( auto& [s,c] : f)
            ans = max(ans,c);
        return ans;
    }
};
