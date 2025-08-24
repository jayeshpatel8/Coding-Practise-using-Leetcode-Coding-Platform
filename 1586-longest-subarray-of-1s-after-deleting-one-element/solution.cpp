class Solution {
public:
    int longestSubarray(vector<int>& nums) {
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
};
