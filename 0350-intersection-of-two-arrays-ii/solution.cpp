class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001]={};
        vector<int> ans;
        for (auto i : nums1) freq[i]++;
        for (auto i : nums2) 
            if (freq[i]) 
                freq[i]--, ans.push_back(i);
        return ans;
    }
};
