class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int cur = -k, ans = 0;
        for (auto &i : nums){
    
            int mi = i-k, ma= i+k;
            if ( cur  < mi) 
                cur = mi + 1, ans++;
            else if (cur > ma)
                continue;   
            else
                cur++,ans++;
        }
        return ans;
    }
};
