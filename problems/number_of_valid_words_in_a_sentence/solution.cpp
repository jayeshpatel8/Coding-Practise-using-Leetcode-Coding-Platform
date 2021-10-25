class Solution {
public:
    int countValidWords(string s) {
        int h= 0,valid=1, ans = 0;
        string w;
        for (int i=0; i<s.size(); i++){
            if (s[i]== ' '){
                if (w.size()) ans += check(w);
                w="";
            }
            else
                w+=s[i];
        }
        if (w.size()) ans += check(w);
        return ans;
    }
    int check(string & w){
        
        for (int i=0, h = 0; i<w.size(); i++){
            if (isdigit(w[i])) return 0;
            else if (isalpha(w[i])) continue;
            else if (w[i] == '-'){
                if (h) return 0;
                ++h;
                if (i==0 || i+1==w.size() || !isalpha(w[i-1]) || !isalpha(w[i+1])) return 0;
            }
            else if (i+1 != w.size()) return 0;
        }
        return 1;
    }
};