class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        set<pair<int,int>>st;
        for (auto i=0; i< divisors.size(); i++){
            int c = 0, d = divisors[i];
            for (auto j : nums)
                c += j%d == 0;
            st.insert({-c,divisors[i]});
        }   
 
        return begin(st)->second;
    }
};