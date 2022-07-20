class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(26);
        for (int i=0;i<s.size(); i++) index[s[i]-'a'].push_back(i);
        int ans= 0;
        for (auto &w : words){
            int idx=-1 , i = 0, j = w.size();
            for (; i<j; i++){
                auto c  = w[i]-'a';
                auto it = upper_bound(begin(index[c]), end(index[c]),idx);
                if (it  == end(index[c])) break;
                idx= *it;
            }
            ans+= i==j;
        }
        return ans;
    }
};