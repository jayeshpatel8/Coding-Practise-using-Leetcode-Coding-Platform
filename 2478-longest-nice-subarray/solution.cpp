class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=1;
        long long cur=0;
        for (int i=0,j=0; i<nums.size(); i++){
            if (cur & nums[i]){
                while (j<i && (cur & nums[i])) cur ^=nums[j++];
                
            }
            cur |=nums[i];

            ans=max(ans, i-j+1);
        }
        return ans;
    }
};
