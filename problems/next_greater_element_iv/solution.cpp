class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ans(nums.size(), -1),p1,p2,t;

        for(int i=0; i<nums.size(); i++){
            while(!p2.empty() && nums[p2.back()] < nums[i])
                ans[p2.back()] = nums[i], p2.pop_back();
            while(!p1.empty() && nums[p1.back()] < nums[i])
                t.push_back(p1.back()), p1.pop_back();
            while(!t.empty()) 
                p2.push_back(t.back()),t.pop_back();
            p1.push_back(i);
        }
        return ans;        
    }
};