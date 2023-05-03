class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int f1[2001]={},f2[2001]={};
        for (auto i : nums1) f1[i+1000]++;
        for (auto i : nums2) f2[i+1000]++;
        vector<int> a,b;
        for (auto i : nums1) 
            if (f1[i+1000]>0 && !f2[i+1000])  f1[i+1000]=-1,a.push_back(i);
        for (auto i : nums2) 
            if (!f1[i+1000] && f2[i+1000]>0)  f2[i+1000]=-1,b.push_back(i);
        return {a,b};
    }
};