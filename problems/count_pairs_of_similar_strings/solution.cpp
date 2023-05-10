class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int,int> m;
        int ans = 0;
        for(auto &s : words){
            int bits=0;
            for (auto c : s) bits |= 1<<(c-'a');
            ans+=  m[bits]++;
        }
        
        return ans;
    }
};