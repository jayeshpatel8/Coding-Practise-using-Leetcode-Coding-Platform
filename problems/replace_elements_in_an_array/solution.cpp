class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        const int N = 1e6 + 1;
        int map[N]={};
        for ( int i = 0; i<nums.size(); i++)
            map[nums[i]]=i+1;
        for (auto & o : operations){
            int i  = map[o[0]];
            map[o[0]] = 0;
            map[o[1]] = i;
        }
        vector<int> ans (nums.size());
        for (int i=1; i< N; i++){
            if (map[i])
                ans[map[i]-1] = i;
        }
        return ans;
    }
};