class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int _xor  = 0,ans = 0;
        for (auto i : nums) _xor ^= i;
        for (int i =0 , j = _xor  ^ k; i<32; i++){
            ans += (j & (1<<i))!=0;
        }
        return ans;
    }
};
