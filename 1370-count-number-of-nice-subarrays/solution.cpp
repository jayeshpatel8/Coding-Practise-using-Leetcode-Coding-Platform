class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;

        for (int i=0, j = 0, odd=0,peven=0; i<n; i++){
            odd += nums[i] & 1;
            if (odd > k ){
                peven=0;
                while (odd > k) odd -= nums[j++]& 1;
            }
            if ( odd == k){
                while ((nums[j] & 1) ==0) peven++,j++;
                ans += peven + 1;
            }
            
            
        }   
        return ans;
    }
};
