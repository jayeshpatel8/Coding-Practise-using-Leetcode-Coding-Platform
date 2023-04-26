class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // s t
        // 1 1 = 0
        // 1 0 = 1
        // 0 1 = 1
        // 0 0 = 0   
        // s ^ t
        vector<int> ans(pref.size());
        ans[0]=pref[0];
        for (int i=1; i<pref.size(); i++)
            ans[i] = pref[i-1]^pref[i];
        return ans;
    }
};