class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        vector<long long> psum(nums.size()+1), ans;
        for (int i=0;i<nums.size(); i++)
            psum[i+1]=psum[i]+nums[i];
        for (auto q : queries){
            auto j = upper_bound(begin(nums),end(nums),q)-begin(nums);
            ans.push_back ( (q* j) - psum[j] + (psum.back()-psum[j])-(nums.size()-j)*q);
        }
        return ans;
    }
};