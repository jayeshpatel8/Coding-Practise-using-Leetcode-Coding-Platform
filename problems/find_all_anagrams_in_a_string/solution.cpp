class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.length(), sn = s.length();
        if ( n==0 || sn < n  ) return vector<int>();
        
        int ch[256]={};
        
        for (int i=0;i<n; i++) {
            ch[p[i]]++;
        }
        vector<int> res;
        
        for (int l=0,r=0,cnt=n; r<sn;){
            if(ch[s[r++]]-->=1) cnt--;
            if (cnt == 0) res.push_back(l);
            if (r-l == n  && ch[s[l++]]++ >=0)cnt++;
        }
        return res;
    }
};