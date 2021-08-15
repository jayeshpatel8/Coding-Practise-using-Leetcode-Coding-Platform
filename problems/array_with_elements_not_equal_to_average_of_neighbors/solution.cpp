class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int inc=1;
        for ( int i=0; i<nums.size()-1; i++){
            if (inc){
                if(nums[i]>nums[i+1])
                    swap(nums[i+1],nums[i]);                
            }else{
                if(nums[i]<nums[i+1])
                    swap(nums[i+1],nums[i]);
            }
            inc =!inc;
        }
        return nums;
    }
};