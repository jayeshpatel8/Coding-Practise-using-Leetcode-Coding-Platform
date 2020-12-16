class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k==0 || nums.size()<2) return false;

        unordered_set<int> m;
         for (int i=0; i< nums.size(); i++){
             if (m.find(nums[i]) != m.end()) return true;
             m.insert(nums[i]);
             if (m.size() > k) m.erase(nums[i-k]);
         }
     return false;   
    }
};