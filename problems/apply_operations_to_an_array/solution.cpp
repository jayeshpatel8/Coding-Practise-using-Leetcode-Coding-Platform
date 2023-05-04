class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int j = 0;
        for (int i=0; i<nums.size();i++){
            if (nums[i]==0) continue;
            if (i+1<nums.size()&& nums[i]==nums[i+1])
                nums[j++]= nums[i++]*2;                            
            else
                nums[j++]=nums[i];         
        }
        while (j<nums.size()) nums[j++]=0;
        return nums;
    }
};