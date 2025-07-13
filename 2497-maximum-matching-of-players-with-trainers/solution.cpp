class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(begin(p), end(p));
        sort(begin(t), end(t));
        int ans = 0;
        for (int i=t.size()-1, j= p.size()-1; i>=0 && j>=0; j--){
            if (p[j] <= t[i]){
                ans++; i--;
            }
        }
        return ans;
    }
};
