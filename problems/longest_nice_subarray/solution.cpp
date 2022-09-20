class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
      int ans =1, a=0;
        for (int i=0, j = 0; i<nums.size(); i++){
            if ( a & nums[i]){
                while (j<i && (a & nums[i]) ){
                    a ^=nums[j++];
                }
            }
            a |= nums[i];
            ans= max(ans, i-j+1);
        }
        return ans;
    }
};