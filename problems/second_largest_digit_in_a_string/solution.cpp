class Solution {
public:
    int secondHighest(string s) {
        int ch[10]={};           
        for  (auto &c : s){
            if (c <'a')
                ch [c-'0']++;
        }
        int cnt=0;
        for (int c = 9 ; c>=0; c--)
            if (ch[c] && ++cnt==2) return c;
         return -1;       
    }
};