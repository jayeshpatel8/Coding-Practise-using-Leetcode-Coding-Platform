class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int f[10]={};
        for (auto i : nums1) f[i]++;
        for (auto i : nums2) f[i]++;
        for (auto i = 1; i<=9; i++)
            if (f[i]>1) return i;
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        return min(nums1[0]* 10 + nums2[0],nums2[0]* 10 + nums1[0] );
    }
};