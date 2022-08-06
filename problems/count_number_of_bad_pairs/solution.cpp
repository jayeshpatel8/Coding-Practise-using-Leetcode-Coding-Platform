class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> m;
        long long N = nums.size();
        long long ans= (N)*(N-1)/2;
        for (int i =0; i<N; i++){
            auto j = nums[i]-i;
            auto it = m.find(j);
            if (it == m.end())m[j]++;
            else
                ans -= it->second, it->second++;
           
        }
        return ans;
    }
};