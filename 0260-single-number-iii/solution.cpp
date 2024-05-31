class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_=0   ;
        for (auto i : nums) xor_ ^= i;
        int bit_set=xor_ & -(long)xor_, num1=0;
        for (auto i : nums) if (i & bit_set) num1 ^= i;
        return {num1, xor_ ^ num1};
    }
};
