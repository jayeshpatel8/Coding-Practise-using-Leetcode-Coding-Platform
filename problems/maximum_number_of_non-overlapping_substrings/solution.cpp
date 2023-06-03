class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> st(26,INT_MAX), en(26);
        for (int i=0; i<s.size();i++){
            auto ch = s[i]-'a';
            en[ch]=i;
            if (st[ch]==INT_MAX) st[ch] = i;
        }
        auto valid_substr = [&](int i){
            int r = en[s[i]-'a'];
            for (int c=i; c<=r; c++){
                if (st[s[c]-'a'] < i) return -1;
                r= max(r,en[s[c]-'a']);
            }
            return r;
        };
        int r=-1;
        vector<string> ans;
        for (int i=0; i<s.size();i++){
            if (st[s[i]-'a'] != i) continue;
            int new_r = valid_substr(i);
            if (new_r != -1){                
                if (i > r) ans.push_back(s.substr(i,new_r-i+1));
                else ans.back() = (s.substr(i,new_r-i+1));
                r = new_r;
            }
        }
        return ans;
    }
    
};

/*
"adefadda" "defadd" "e" "f" "ccc"

abbaccd abba bb cc d 

abcbac 
*/