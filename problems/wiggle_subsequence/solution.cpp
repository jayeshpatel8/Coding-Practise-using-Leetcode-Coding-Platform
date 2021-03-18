class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 1;
       
        int ans,prev=nums[0]-nums[1];
        ans = prev==0? 1: 2;
        const int shift = (sizeof(int)*8-1);
        for(int i=2; i<n; i++){
            int  diff = nums[i-1]-nums[i];
            if(diff ==0 ) continue;
            if(prev==0) {prev=diff,ans++;};
            if((prev ^ diff ) >> shift) {
                ans++, prev  = diff;
            }
            else
                continue;            
        }
        return ans;
    }
};