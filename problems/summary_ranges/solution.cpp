class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i=0; i<nums.size(); i++){
            string str =to_string(nums[i]);
            int j=i+1;
            for (; j<nums.size(); j++){
                if (nums[j] != nums[j-1]+1) break;
            }
            if (i+1 < j) str+="->"+to_string(nums[j-1]), i=j-1;
            ans.push_back(str);
        }
        return ans;
    }
};