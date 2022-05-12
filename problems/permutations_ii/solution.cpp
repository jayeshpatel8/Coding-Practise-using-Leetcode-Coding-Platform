class Solution {
public:
    vector<vector<int>> ans;
    int N = 0;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> t;
        N = nums.size();
        sort(begin(nums), end(nums));
        perm(nums,0, t);
        return ans;
    }
    void perm(vector<int>& nums, int mask, vector<int> &t){
        if (mask == (1<<N)-1) {
            ans.push_back(t);
            return;
        }
        int prev=20;
        for ( int i=0; i<N; i++){
            if (mask & (1<<i) || nums[i] == prev) 
                continue;
            prev=  nums[i];
            t.push_back(prev);
            perm(nums,mask | (1<<i), t);
            t.pop_back();
        }
    }
};