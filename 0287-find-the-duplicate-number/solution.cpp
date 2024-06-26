class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast= slow;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(slow != fast);
        slow = nums[0];
        while(slow != fast) slow=nums[slow],fast=nums[fast]; // simple start from 0 and match point to find loop starts point
        return slow;
    }
};
