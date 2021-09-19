class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size(), ans = 0;
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        
        for(int i=0, j=0, N= nums.size(); i<N; i++){            
            for (int K=nums[i]+n; j<N && nums[j] < K; j++)
                ;
            ans  = max(ans, j-i);
        }
        return n - ans ;
    }
};