class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>m;
        int cnt =0;
        for (auto i : nums)
            cnt=  max(cnt, ++m[i%space]);
        int ans=INT_MAX;
        for (auto i : nums){
            if (cnt == m[i%space]){
                ans=min(ans, i);
                
            }
        }
        return ans;
    }
};