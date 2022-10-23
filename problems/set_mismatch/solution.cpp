class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> map;
        int dup = 0, missing = 0;
        for (auto i : nums) map[i]++;
        for (int i=1; i<=nums.size(); i++){
            if (map[i]==0) missing = i;
            else  if (map[i]==2) dup = i;
        }
        
        return {dup,missing};
    }
};