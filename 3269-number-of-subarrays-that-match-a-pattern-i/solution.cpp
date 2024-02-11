class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        for (int i=1; i<nums.size(); i++){
            if (nums[i] > nums[i-1]) nums[i-1] = 1;
            else if (nums[i] < nums[i-1]) nums[i-1] = -1;
            else nums[i-1] = 0;
        }
        int  ans = 0;
        for (int i=0; i<nums.size()-1; i++){
            int j=0;
            for (int k=i; k<nums.size() && j<pattern.size(); j++){
                if (pattern[j] !=  nums[k++])break;
            }
            if (j==pattern.size())
            ans++;
        }
        return ans;
    }
};
