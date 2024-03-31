class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;

        for (int  i=0, j=0, cnt = 0, prefix = 0; i<nums.size(); i++){
            auto n = nums[i];
            if (m[n]++==0) cnt++;
            
            if(cnt > k) --m[nums[j++]] , cnt--, prefix = 0;
            
            while (m[nums[j]] > 1) prefix++, --m[nums[j++]];
            if (cnt == k) ans += 1 + prefix;
        }
        return ans;
    }
};
