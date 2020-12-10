class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=1, candidate=nums[0];
        for (int i=1; i< nums.size(); i++){
            if (candidate == nums[i]) count++;
            else if (count == 1) {
                 candidate=nums[i];
            }else count--;
        }
        return candidate;
    }
};