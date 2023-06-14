class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
       int mod = 1e9 + 7 ,ans =0 ,psum = 0;

        for (int i=0; i<nums.size(); i++)
            nums[i] += (s[i]=='R' ? d : -d); 
        sort(begin(nums),end(nums));

        for (int i=0; i<nums.size(); i++){
            ans = (ans + i * (long long)nums[i] - psum)%mod;
            psum = (psum + (long long)nums[i])%mod;
        }
        return ans;
    }
};