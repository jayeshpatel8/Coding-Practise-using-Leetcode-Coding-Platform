class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto N  = nums.size();
        vector<bool> marked (N);
         vector<int> idx(N);
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](auto a, auto b)->bool{
                return nums[a] == nums[b] ? a<b: (nums[a] < nums[b]);
            });
        long long ans = 0;
        for (int i=0; i<N; i++){
            auto j = idx[i];
            if (marked[j]) continue;
            marked[j]=true;
            ans += nums[j];
            if (j>0) marked[j-1]=true;
            if (j+1< N ) marked[j+1]=true;
        }
        return ans;
    }
};