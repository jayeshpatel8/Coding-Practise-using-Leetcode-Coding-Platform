class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int neg=0,pos=0,ans=0;

        for (auto i : nums){
            pos = max({0,pos + i, i });
            neg = min({0,neg + i, i});
            ans= max({ans,pos,abs(neg)});
        }
        return ans;
    }
};
