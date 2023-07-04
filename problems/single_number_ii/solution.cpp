class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int f[32]={};
        for (auto  i : nums){
            for (int j=0; j<32; j++)
                f[j] += (i & (1<<j))!=0;
        }       
        int ans = 0; 
        for (int i=0; i<32; i++){
             if (f[i] %3 != 0 )
                ans |= 1<<i;            
        }
        return ans;
    }
};
