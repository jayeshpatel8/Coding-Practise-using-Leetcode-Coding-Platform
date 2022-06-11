class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& po, long long su) {
        int N = spells.size();
        sort(begin(po) , end(po));
        vector<int> ans(N,0);
        for (int i=0; i<N; i++){
            long long num = (su / spells[i])  + ((su % spells[i])!=0);
            auto it = lower_bound(begin(po) , end(po), num);
            
            ans[i] = end(po) - it;
        }
        return ans;
    }
};