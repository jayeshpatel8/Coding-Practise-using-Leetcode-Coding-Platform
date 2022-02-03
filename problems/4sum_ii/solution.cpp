class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for (auto i : nums4) 
            for (auto j : nums3)
                map[i+j]++;
        int ans = 0;
        for (int i=0,n = nums1.size(); i<n; i++){
            for (int j=0; j<n; j++){
                ans += map[-(nums1[i] + nums2[j])];
            }
        }
        return ans;
    }
};