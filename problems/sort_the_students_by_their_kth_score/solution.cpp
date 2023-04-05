class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

    sort(begin(score), end(score), [&](const auto &s1, const auto &s2){ return s1[k] > s2[k]; });
    return score;

        int N= score[0].size(), M = score.size();
        vector<array<int,2>> kcol;
        for (int r=0; r<M; r++) kcol.push_back({score[r][k],r});
        sort(rbegin(kcol),rend(kcol));
        
        vector<vector<int>> ans(M,vector<int>(N));
        for (int r=0; r <M; r++){
            int r1 = kcol[r][1];
            ans[r]=score[r1];
        }
        
        return ans;
    }
};