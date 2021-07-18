class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt=0, b[128]={};
        for (auto i : brokenLetters) b[i]++;
        
        for (int i =0; i<text.size(); i++){
            if (text[i]==' ') cnt++;
            else if (b[text[i]]){
                while(i<text.size() && text[i]!=' ') i++;
            }else if (i+1 == text.size())cnt++;
        }
        return cnt;
    }
};