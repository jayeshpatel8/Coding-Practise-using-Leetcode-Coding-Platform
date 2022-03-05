class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int freq[1001]={}, ans = 0;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i]==key)
                freq[nums[i+1]]++;
            if (freq[nums[i+1]] > freq[ans])
                ans = nums[i+1];
        }
        return ans;
    }
};