class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for (auto i=0; i< nums.size(); i++) map[nums[i]].push_back(i);
        vector<long long> ans(nums.size());
        for (auto &[ke,i] : map){            
            auto total = accumulate(begin(i),end(i),0L) ;
            long long N = i.size() , presum=0,postsum=total,k=0;
            for (auto j : i){
                postsum -=j;
                ans[j] += k * j;
                ans[j] -= presum;
                ans[j] += postsum;
                ans[j] -= j * (N- k - 1);
                presum += j;
                k++;
            }
        }
        return ans;
    }
};