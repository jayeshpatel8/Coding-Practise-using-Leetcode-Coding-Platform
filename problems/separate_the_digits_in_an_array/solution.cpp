class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto i :nums){
            auto s = to_string(i);
            for (auto c : s) ans.push_back(c-'0');
        }
        return ans;
    }
};