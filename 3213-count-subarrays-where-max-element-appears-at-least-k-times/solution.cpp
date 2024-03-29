class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0; 
        int m = *max_element(begin(nums),end(nums)) ,cnt= 0 ;
        for (int i=0, j =0; i < nums.size(); i++){
            cnt += nums[i] == m;
            while (cnt >= k)
                cnt -= nums[j++]==m;
            ans +=  j;
            
        }
        return ans;
    }
};
