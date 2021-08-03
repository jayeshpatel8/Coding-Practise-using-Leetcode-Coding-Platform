class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> temp;
        bt(nums,0,{temp});
        return ans;
    }
    void bt(vector<int>& nums, int i, vector<int>& temp){
        ans.push_back(temp);
        for (int j=i ; j<nums.size(); j++){
            if (j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            bt(nums,j+1,temp);
            temp.pop_back();
        }
    }
    
};