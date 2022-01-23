class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto i : nums) m[i]++;
        vector<int> ans;
        
        for (auto i : nums){
            if (m.count(i-1) || m.count(i+1) ) continue;
            if (m[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};