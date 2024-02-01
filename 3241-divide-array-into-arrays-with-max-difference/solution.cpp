class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>  ans;
        sort(begin(nums),end(nums));
                
        for (auto i=0; i< nums.size(); i+=3){
            int n = nums[i]+k;
            
                if (nums[i+2] >n) return {};
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};
