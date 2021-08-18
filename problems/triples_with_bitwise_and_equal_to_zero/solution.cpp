class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int N = 1<<16;
        int freq[1<<16]={},  ans = 0;

        for(auto i : nums)
            for(auto j : nums)
                    freq[j & i]++;
        for(int i=0; i<N; i++)
            for(auto j : nums)
                    if ((j & i) == 0)
                        ans +=freq[i];
                    
        return ans;
    }
};