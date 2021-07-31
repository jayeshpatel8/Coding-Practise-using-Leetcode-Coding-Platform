class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001]={};
        vector<int> ans;
        for (auto n : nums1) freq[n]++;
        for (auto n : nums2) 
            if(freq[n])
                freq[n]--, ans.push_back(n);
        return ans;
    }
};