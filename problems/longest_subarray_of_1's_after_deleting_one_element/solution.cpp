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
        int ans=0, zero=0,j=0,one=0;
        for (auto i=0; i<nums.size(); i++){
            if (nums[i])
                one++;
            else 
                zero++;
            while (zero > 1)
                if( nums[j++]) one--; else zero--;

            ans = max(ans, one-(!zero));
        }
        return ans;
    }
};