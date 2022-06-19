class Solution {
public:
    string greatestLetter(string s) {
        int ch[128]={};
        for (auto c : s){
            ch[c]++;
        }
        
        char ans=0;
        for (auto c ='A',d='a'; c <='Z'; c++,d++){
            if (ch[c] >0 && ch[d]>0)
                ans= c;
        }
        return ans!=0 ? string(1,ans) : "";
    }
};