class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int N= nums.size(), ans = 0;
        for (int i=1; i<(1<<N); i++){
            int x=0;
            for (int j=0; j<N; j++){
                if ( i & (1 << j))
                    x ^= nums[j];
            }
            ans += x;
        }
        return ans;
    }
};
