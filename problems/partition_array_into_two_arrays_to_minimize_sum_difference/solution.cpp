class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2; 
        vector<int> left(nums.begin(), nums.begin()+n), right(nums.begin()+n, nums.end()); 
        vector<vector<int>> val(n+1);
        for (int mask=0; mask < (1<<n); mask++){
            int diff=0, setbits = __builtin_popcount(mask);
            for (int i=0; i<n; i++){
                diff += (mask & (1<<i))? left[i] : -left[i];
            }
            val[setbits].push_back(diff);
        }
        for (auto &v : val) sort(begin(v), end(v));
        int ans = INT_MAX;
        for (int mask=0; mask < (1<<n); mask++){
            int diff=0, setbits = n - __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? right[i] : -right[i]; 
            auto it  = lower_bound(val[setbits].begin(), val[setbits].end(), -diff);
            if (it != begin(val[setbits])) ans = min(ans, abs(diff  + *prev(it)));
            if (it != end(val[setbits])) ans = min(ans, abs(diff + *it));
            
        }        
        return ans; 
    }
};