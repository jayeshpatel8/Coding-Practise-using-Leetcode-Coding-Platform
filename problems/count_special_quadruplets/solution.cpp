class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        for ( int i = 0; i<nums.size(); i++){
            for ( int i2 = i+1; i2<nums.size(); i2++)
                for ( int i3 = i2+1; i3<nums.size(); i3++){
                    int sum  = nums[i] + nums[i2] + nums[i3];
                    for ( int i4 = i3+1; i4<nums.size(); i4++){
                        if (nums[i4] == sum)
                            ans++;
                    }
                }
        }
        return ans;
    }
};