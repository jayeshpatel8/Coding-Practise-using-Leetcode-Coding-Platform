class Solution {
public:
    int maximumLength(string s) {
        vector<int> ch[26];
        int last = s[0], cnt=0; 
        for (auto c : s){
            if (c == last) cnt++;
            else{
                ch[last-'a'].push_back(cnt);
                cnt=1;last=c;
            }
        }
        ch[last-'a'].push_back(cnt);
    int ans=-1;
        for (int c=0; c<26; c++){
            int sz = ch[c].size();
            if (sz == 0) continue;
            sort(begin(ch[c]), end(ch[c]));
            
            if (sz >=3){
                ans= max(ans , min({ch[c][sz-1],ch[c][sz-2],ch[c][sz-3]}));
            }
            if (sz>=2 && (ch[c][sz-1]+ch[c][sz-2]) > 2)
                ans= max(ans, min(ch[c][sz-1]-1, ch[c][sz-2]));
            //if (ans <1 && ch[c][sz-1] >2) ans=1;
            if (ch[c][sz-1] >2)
                ans= max(ans, ch[c][sz-1]-2);
        }
        return ans;
    }
};
