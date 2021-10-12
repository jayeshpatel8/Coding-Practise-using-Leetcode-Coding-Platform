class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int freq[101][3]={};
        for (auto i : nums1) freq[i][0]++;
        for (auto i : nums2) freq[i][1]++;
        for (auto i : nums3) freq[i][2]++;
        vector<int> ans;
        for (int i=1; i<=100; i++){
            if (freq[i][0]){
                if (freq[i][1] || freq[i][2]){
                    freq[i][1] = freq[i][2] = 0;
                    ans.push_back(i);
                }
            }
        }
        for (int i=1; i<=100; i++){
            if (freq[i][1]){
                if (freq[i][2]){
                     ans.push_back(i);
                }
            }
        }        
        return ans;
    }
};