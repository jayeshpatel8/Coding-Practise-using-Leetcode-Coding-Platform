class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        vector<int> t;   
        subsetsWithDup(nums,res,t,0);
        return res;
    }
    private:
    void subsetsWithDup(vector<int>& nums ,vector<vector<int>> & res, vector<int>&t, int pos) {
        if (pos > nums.size()) {        
            res.push_back(t);
            return ;
        }
        res.push_back(t);   
        
        for (int i =pos; i < nums.size(); i++)
        {
            if (i-1>=pos && nums[i-1] == nums[i]) continue;
            t.push_back(nums[i]);    
            subsetsWithDup(nums,res,t,i+1);
            t.pop_back();    
        }
    }
};