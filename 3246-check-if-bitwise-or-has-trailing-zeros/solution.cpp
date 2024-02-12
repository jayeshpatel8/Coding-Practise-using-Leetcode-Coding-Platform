class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int c = 0;
        for (auto i : nums)
            
            c  += (i & 1)==0;
        return c >1;
    }
};
