class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m={{0,1}};
        int psum=0,ans=0;
        for (int i=0; i<nums.size(); i++){
            psum += nums[i];
            auto c = m[psum-k];
            ans +=c;
            m[psum]++;
        }
        return ans;
    }
};