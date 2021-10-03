class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = (rolls.size()  + n ) * mean  - accumulate(begin(rolls),end(rolls),0);
        if (sum > 6*n || sum/ n < 1) return {};
        int rem = sum % n;
        vector<int> ans(n, sum/ n);
        for (int i=0; i<rem; i++)
            ans[i]+=1;
        return ans;
    }
};