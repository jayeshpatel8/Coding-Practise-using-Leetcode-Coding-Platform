class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        for (int  next = 0, i=0; i<=next; i++){
            next= max(next, i + nums[i]);
            if (next >= N -1) return true;
        }
        return 0;
    }
};
 