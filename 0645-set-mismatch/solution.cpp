class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums) m[i]++;
        int n = -1;
        vector<int> ans;
        for (int i=0; i < nums.size(); i++){
            if (m.count(i+1)) {
                if (m[i+1]==2) ans.push_back(i+1);
            }
            else
                n = i+1; 
        }
        ans.push_back(n);
        return ans;
    }
};
