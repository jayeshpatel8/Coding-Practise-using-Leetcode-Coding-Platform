class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> f(50001);
        int mi = INT_MAX;
        for (auto i : nums) mi= min(mi,i),f[i]++;
        int ans = 0,freq=0;
        for (auto i = 50000; i > mi; i--){
            freq += f[i];
            if (f[i])
                ans +=freq;
        }
        return ans ;
    }
};
