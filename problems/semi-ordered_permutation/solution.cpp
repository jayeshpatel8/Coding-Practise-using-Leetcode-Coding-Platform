class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int a=0, N=nums.size(),b=0;
        for (int i=0; i<N && !(a && b); i++){
            if (nums[i] == 1) a=i;
            else if (nums[i] == N) b=i;
        }
        return a + N -1 - b - (b<a);
    }
};