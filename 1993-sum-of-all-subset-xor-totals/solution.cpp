class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int N =  nums.size();
        int ans = 0;
        for  (int i=1; i < (1<<N); i++){
            int _xor= 0;
            for (int j=0; j<N; j++){
                if ( i & (1<<j))
                    _xor ^= nums[j];
            }
            ans += _xor;
        }
        return ans;
    }
};
