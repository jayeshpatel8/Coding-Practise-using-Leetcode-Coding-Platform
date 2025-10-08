class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int>  ans(spells.size());
        
        for (int i=0, N = potions.size(); i<spells.size(); i++){
            ans[i] = end(potions)- lower_bound(begin(potions), end(potions), (success + spells[i]-1)/spells[i]) ;

        }
        return ans;
    }
};
