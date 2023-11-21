class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        //[42,11,1,97]
        //rev[42,11,1,97]
        for (int i=0 ; i< nums.size(); i++){
            int rev=0, n=nums[i];
            while (n>0){
                rev = rev * 10 + (n%10);
                n /= 10;
            }
            nums[i] = nums[i]-rev;
        }
        map<int,long> M;
        long ans=0;
        int mod = 1e9 + 7;
        for (auto i : nums){
            int c = M[i];
            if (c)                
                ans  = (ans + c)% mod;               
            
            M[i] = (c + 1 ) % mod;
        }
        return ans;
    }
};
