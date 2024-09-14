class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> idx;
        int m =  *max_element(begin(nums),end(nums)), ans= 1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==m){
                int c =0;
                while (i < nums.size() && nums[i]==m)
                    c++,i++;
                ans= max(ans,c);
            }
        }
        return ans;
    }
};
