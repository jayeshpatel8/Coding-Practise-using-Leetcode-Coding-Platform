class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,cnt=0;
        //  [1,1,0,0,0,1,1,0]  k=2
        for (int i=0,j=0; j<nums.size();j++){
            if (nums[j]==0) cnt++;
            while (cnt > k) {
               if (nums[i++] == 0) cnt--;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
        
    }
};