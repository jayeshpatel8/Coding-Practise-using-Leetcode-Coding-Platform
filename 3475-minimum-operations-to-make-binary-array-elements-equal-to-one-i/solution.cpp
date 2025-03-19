class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i=0;  i<nums.size();i++){
            if (nums[i]) continue;
            if (i+2 >= nums.size()) return -1;
            for (int j=i+2; j>=i; j--)
                nums[j] = !nums[j];
            ans++;
        }
        return ans;
    }
};
