class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++)
            nums[i-1] = nums[i] -nums[i-1];
        int ans  =  -1;
        for (int i=0, j; i<nums.size()-1; i++){
            if (nums[i]==1){
                j=i+1;
                while (j<nums.size() && (nums[j] + nums[j-1])==0){
                    j++;
                    
                }
                ans= max(ans, j-i + (j<nums.size()));
                i=j-1;
            }
        }
        return ans;
    }
};
// [1,-1,1,1]