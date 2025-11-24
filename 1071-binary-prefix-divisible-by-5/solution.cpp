class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int j=0;
        vector<bool> ans;
        for (auto  i : nums){
            j<<=1;
            if (i) j |=1;
            j%=5;
            ans.push_back(j==0);
        }
        return ans;
    }
};
