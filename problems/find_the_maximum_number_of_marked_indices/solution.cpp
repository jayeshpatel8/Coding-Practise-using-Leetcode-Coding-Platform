class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans = 0;
        for (int N=nums.size(), j= 0, i = N/2; j<N/2 && i <N; ){
            if (2 * nums[j] <= nums[i]){
                ans +=2;j++;
            }
            i++;
        }
        return ans;
    }
};