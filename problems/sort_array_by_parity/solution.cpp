class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int ev=0,odd=nums.size()-1; ev < odd; ){
            if ( nums[ev] & 1){
                swap(nums[ev],nums[odd--]);
            }
            else ev++;
        }
        return nums;
    }
};