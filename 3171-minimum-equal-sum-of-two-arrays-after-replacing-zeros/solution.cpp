class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0,s2=0,z1=0,z2=0;
        
        for (auto i : nums1)
            if( i) s1+=i;
            else z1++;
        
        for (auto i : nums2)
            if( i) s2+=i;
            else z2++;
        
        auto a = s1+z1, b = s2+z2;
            
        if (a > b) return z2==0? -1: a;
        if (a < b) return z1==0? -1: b;
        return a;
    }
};
