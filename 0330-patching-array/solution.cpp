
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        size_t patches = 0, sum = 1, i = 0, N = nums.size();
        while (sum <= n){
            if ( i < N && nums[i] <= sum){
                sum += nums[i++];
            }
            else{
                sum *=2;
                patches++;
            }
        }
        return patches;
    }
};
