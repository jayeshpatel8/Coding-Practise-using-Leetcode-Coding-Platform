class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> M;
        int ans = 1;
        for(auto i : arr)
            ans = max (ans , M[i] = 1 + M[i-diff]);
        
        return ans;
    }
};