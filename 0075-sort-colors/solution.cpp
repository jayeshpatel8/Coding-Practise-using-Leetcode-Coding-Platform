class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,t=nums.size()-1, i = 0;
        while( i <= t){
            if (nums[i] == 0){
                swap(nums[i], nums[z++]);
                if (nums[i] <2) i++;
            }
            else if (nums[i] == 2){
                swap(nums[i], nums[t--]);
            }
            else i++;
        }
    }
};
