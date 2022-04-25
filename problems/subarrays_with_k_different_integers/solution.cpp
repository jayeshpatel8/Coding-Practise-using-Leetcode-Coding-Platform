class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;

        for (int  i=0, j=0, cnt = 0, prefix = 0; i<nums.size(); i++){
            if (m[nums[i]]++ == 0) cnt++;
            if (cnt > k ) prefix=0, --m[nums[j++]],--cnt;
            while (m[nums[j]] > 1) prefix++, m[nums[j++]]--;
            
             
            if (cnt == k) ans+=1 +prefix;
        }
        return ans;
    }
};