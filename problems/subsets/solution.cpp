void backtrack(vector<int>& nums, int i,vector<int> &cur, vector<vector<int>> & res){
    
    if (i == nums.size()) { res.push_back(cur); return;}
    
    cur.push_back(nums[i]);
    
    backtrack(nums,i+1,cur,res);
    cur.pop_back();    
    backtrack(nums,i+1,cur,res);
    
    
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
        vector<int> cur;
    
        backtrack(nums,0,cur,res);
        return res;        
    }
};