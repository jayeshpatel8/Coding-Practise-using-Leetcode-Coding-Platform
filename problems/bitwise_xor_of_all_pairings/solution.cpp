class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int N1=  nums1.size(), N2= nums2.size(), ans=  0;
        if (N1 & 1)
            ans = accumulate(begin(nums2), end(nums2),0,[](auto a, int b){return a ^ b;});

        if (N2 & 1)
            ans = accumulate(begin(nums1), end(nums1),ans,[](auto a, int b){return a ^ b;});
        return ans;
    }
};