class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(rbegin(nums),rend(nums));
        long long pre=0, ans = 0;
        for (auto i : nums){
            pre+=i;
            if (pre<=0) return ans;
            ans++;
        }
        return ans;
    }
};