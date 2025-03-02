class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        for ( int i=0, j =0; i< nums1.size() || j <nums2.size(); ){
            auto id=0, v=0;
            auto a = i<nums1.size() ? nums1[i][0] : INT_MAX;
            auto b = j<nums2.size() ? nums2[j][0] : INT_MAX;
            if (a == b){
                v = nums1[i][1] + nums2[j][1];
                id = nums1[i++][0];
                j++;
            }
            else if ( a <b )
            {
                v = nums1[i][1] ;
                id = nums1[i++][0];
            }
            else {
                v = nums2[j][1] ;
                id = nums2[j++][0];
            }
            ans.push_back({id,v});
        }
        return ans;
    }
};
