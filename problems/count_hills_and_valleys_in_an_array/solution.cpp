class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        for (int i=1; i<nums.size(); i++){
            if (i==0 || nums[i] == nums[i-1]|| i==nums.size()-1) continue;
            int higher= nums[i] > nums[i-1], higher2=-1;
            for (int j=i+1; j<nums.size(); j++ ){
               if (nums[i] == nums[j])
                    continue;                                
                higher2=nums[i] > nums[j];
                i=j-1;
                break;
            }
            ans += higher == higher2;
        }
        return ans;
    }
};