class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;
        for( auto i : nums){
            int diff = k - i;
            if (diff > 0 && m[diff] > 0){
                ans++;
                m[diff]--;
            }
            else
                m[i]++;
        }
        return ans;
    }
};