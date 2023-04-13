class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        sort(begin(pl),end(pl));
        sort(begin(tr),end(tr));
        int ans = 0;
        for (int i=0, j =0; j<pl.size() && i<tr.size(); i++){
            if (pl[j]<= tr[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};