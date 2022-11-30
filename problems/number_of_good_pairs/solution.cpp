class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto i : nums) freq[i]++;
        int ans = 0;
        for ( auto & [k,v] : freq){
            if (v>1){
                ans += (v-1)*v/2;
            }
        }
        return ans;
    }
};