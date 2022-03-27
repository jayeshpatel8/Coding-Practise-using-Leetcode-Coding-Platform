class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int f1[2001]={},f2[2001]={};
        for (auto i:nums1) f1[i+1000]=1;
        for (auto i:nums2) f2[i+1000]=1;
        vector<vector<int>> ans;
        vector<int> ans1, ans2;
        int  i=0, j=0;
        for ( ; i <2001; i++){
            if ( f1[i] == f2[i]){continue;
            }
            else if (f1[i]){
                ans1.push_back(i-1000);
            }
            else
                ans2.push_back(i-1000);
        }
       
        return {ans1,ans2};
    }
};