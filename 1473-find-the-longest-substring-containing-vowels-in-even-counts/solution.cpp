class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> idx;
        idx[0]=-1;
        int b=0, ans=0;
        string v="aeiou";
        for (auto i=0; i<s.size(); i++){
            auto c =  s[i];
            if (v.find(c) != string::npos) {
                b ^= 1 << (c-'a');
            }
            if (idx.count(b)){
                ans = max(ans, i-idx[b]);
            }
            else 
                idx[b]=i;
        }
        return ans;
    }
};
