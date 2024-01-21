class Solution {
public:
    int rob(vector<int>& nums) {
        int p1=0,p2=nums[0];
        for (int i=1; i<nums.size(); i++){
            int t= p1 + nums[i];
            p1 = p2;
            p2 = max(t,p2);
        }
        return p2;
    }
};
