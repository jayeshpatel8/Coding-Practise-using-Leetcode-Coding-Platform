class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans{words[0]};
        for (int i=1,  j = 0; i<groups.size(); i++){
            if (groups[j] == groups[i]) continue;
            ans.push_back(words[i]);
             j = i;
        }
        return ans;
    }
};
