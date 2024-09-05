class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();   
        int sum = (n + m) * mean - accumulate(begin(rolls),end(rolls),0L);
        if (sum > 6*n || sum/ n < 1) return {};
        int rem = (sum % n) ;
        
        vector<int> ans(n,sum/n);
        for (auto& i : ans){
             if (rem){
                i++, rem--;
             }
             else break;
        }
        return ans;
    }
};
