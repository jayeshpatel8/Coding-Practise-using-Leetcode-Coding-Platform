class Solution {
public:
    int longestSubarray2(vector<int>& nums) {
        int ans=0, flip=1;
        for (auto i=0 ,j = 0; i<nums.size(); i++){
            if (nums[i]==0)
                flip--;
            if (flip < 0){
                while (nums[j++]) {;}
                flip++;
            }
            ans = max(ans, i-j);
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums) {
        int ans=0,j=0,f[2]={};
        for (auto i=0; i<nums.size(); i++){
            f[nums[i]]++;
            
            while (f[0] > 1) f[nums[j++]]--;

            ans = max(ans, f[1]-(!f[0]));
        }
        return ans;
    }
};