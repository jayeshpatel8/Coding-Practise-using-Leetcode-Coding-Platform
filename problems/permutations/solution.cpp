void permute_rec(vector<int>&nums,int idx, vector<vector<int>> & r)    
{
    if (idx>=nums.size()) {r.push_back(nums); return;}
    
        for (int i=idx; i<nums.size(); i++)
        {
           
            swap(nums[i], nums[idx]);      
            permute_rec(nums,idx+1,r);
            swap(nums[i], nums[idx]);                                
            
        }            
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int l=nums.size();
        vector<vector<int>> r;
        
                              
   permute_rec(nums,0,r);
        return r;
    }
};