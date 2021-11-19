class Solution {
public:
    int ch[128]={}, ans = 0;
    int countVowelSubstrings(string word) {
        
        
        for (int i=0; i<word.size(); i++){
            if (isvowel(word[i])){
                
                for (int j=i; j<word.size(); j++){
                    if (isvowel(word[j])){                        
                        ch[word[j]]=1;
                        ans += (allvowel() == 5);                        
                    }
                    else
                     break;
                }
            }
            clear();
        }
        return ans;
    }
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int allvowel(){
        return (ch['a']+ch['e']+ch['i']+ch['o']+ch['u']);
    }
    void clear(){
        ch['a']=ch['e'] =ch['i'] =ch['o'] =ch['u'] = 0;
    }
};