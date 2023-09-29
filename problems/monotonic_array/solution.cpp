class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int diff = 0;
        for (int i=1; i<nums.size(); i++){
            int d  = nums[i-1] - nums[i];
            if (!d) continue;
            if (!diff) diff = d;
            else{
                if ((d <0 && diff < 0) || (d>0 && diff>0)) continue;
                else return false;
            }
        }
        return true;
    }
};