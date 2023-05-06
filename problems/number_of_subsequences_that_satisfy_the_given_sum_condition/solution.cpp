int pow2[100001]={};
class Solution {
public:
int ans = 0,mod = 1e9+7;

    int numSubseq(vector<int>& nums, int target) {
        
        if (!pow2[0]){
            pow2[0]=1;
            for (int i1=1; i1<100000; i1++)
                pow2[i1] = (pow2[i1-1]<<1)%mod;            
        }
        
        
        sort(begin(nums),end(nums));

        for (int i=0, j = nums.size()-1; i<=j;  ){
            if (nums[i] + nums[j] > target) j--;
            else
                ans = (ans +pow2[j-i++]) %mod;
        }
        return ans;
    }
};