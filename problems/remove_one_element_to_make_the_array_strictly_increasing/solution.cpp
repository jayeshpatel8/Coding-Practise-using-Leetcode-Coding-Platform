class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int changed=0;
        for (int i=1; i<nums.size(); i++){
            if (nums[i-1] < nums[i]) continue;
           
            if(changed++) return false;
            if (i > 1){
                if ((nums[i-2]>=nums[i])) nums[i]  = nums[i-1];
            }

        }
        return true;
    }
};