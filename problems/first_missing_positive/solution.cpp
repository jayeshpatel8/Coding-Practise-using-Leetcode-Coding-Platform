class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> hash;
        int j=0;
        for (int i=0; i< nums.size();i++)
            if (nums[i]>0){
                hash.insert(nums[i]);
                j++;
            }
        int i=1;
        for (; j>0;j--,i++)
            if (hash.find(i)==hash.end())
                return i;
        return i;
    }
};