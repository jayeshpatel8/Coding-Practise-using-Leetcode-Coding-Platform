class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = 1 << nums.size();
        int ans = 0;
        for (int i=1; i<n; i++){
            int ans1 = 0;
            for ( int j=0, k =i; k; j++ ){
                int bit = 1<<j;
                if (bit & k){
                    ans1 ^=nums[j];
                    k&=k-1;
                }                
            }
            ans += ans1;
        }
        return ans;
    }
};