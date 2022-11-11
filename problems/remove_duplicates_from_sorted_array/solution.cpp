class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (auto  v : nums)
            if (v != nums[j]) nums[++j]=v;
        return j+1;
    }
};