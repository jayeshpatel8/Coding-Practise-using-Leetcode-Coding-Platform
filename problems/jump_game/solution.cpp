class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> jump(nums.size(),0);
        if (nums.size()<2) return true;
        int m=0;
        for (int i=0; i< nums.size()-1;i++)
        {
            if (i+nums[i]>m && m>=i)
            {
                m=i+nums[i];
                if (m>=nums.size()-1) return true;
            }
        }
        cout << m ;
        return false;
    }
};