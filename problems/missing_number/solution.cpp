class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int xored=N;
        for (int i=0; i<N; i++)
            xored ^= i ^ nums[i]; 
         return xored;
    }
};