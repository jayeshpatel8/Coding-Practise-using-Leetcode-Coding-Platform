class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=-1,pprev=-1,i=0,n=nums.size();
        for (; i<n; i++)
            if (nums[i]==0){prev=i++; break;}
       
        if (i==n) return n-1;
        int ans=0;
        for (; i<n; i++)
            if (nums[i]==0){
                ans= max(ans,i-pprev-2);
                pprev=prev,prev=i;
            }
        return ans= max(ans,i-pprev-2);
        
    }
};