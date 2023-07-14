class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> map;
        int ans = 1;
        for (auto i : arr){
                map[i] = max(map[i], 1 + map[i-difference]);
                ans= max(ans, map[i]);
        }   
        return ans;
    }
};