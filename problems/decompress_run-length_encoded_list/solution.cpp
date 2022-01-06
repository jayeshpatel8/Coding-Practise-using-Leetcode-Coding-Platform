class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for ( int i=0; i<nums.size(); i++){
            int freq = nums[i++], v = nums[i];
            while(freq-->0){
                ans.push_back(v);
            }
        }
        return ans;
    }
};