class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {        
        int N = nums.size(), p =0, n = 0;
        vector<int> ans(N);
        for (int i=0; i<N; i+=2){
            while(nums[p]<0) p++;
            while(nums[n]>0) n++;
            ans[i] = nums[p++];
            ans[i+1] = nums[n++];
        }
        return ans;
    }
};