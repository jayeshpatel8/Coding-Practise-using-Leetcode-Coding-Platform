class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> ch(26);
        for (int i=0; i<s.length(); ++i) ch[s[i]-'a'].push_back(i);
        int ans=0;
        for (auto w : words){
            int i=-1,j=0;
            for (; j< w.size(); j++){                
                int cha = w[j] - 'a';
                auto it = upper_bound(begin(ch[cha]), end(ch[cha]), i);
                if (it == end(ch[cha])) break;
                i = *it;
            }
            ans+= (j == w.size()) ;
        }
        return ans;
    }
};