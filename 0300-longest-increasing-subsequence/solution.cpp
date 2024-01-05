class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(auto i : nums){
            auto it = lower_bound(begin(lis), end(lis),i);
            if (it != end(lis)) 
                *it = i;
            else lis.push_back(i);
        }
        return lis.size();
    }
};
