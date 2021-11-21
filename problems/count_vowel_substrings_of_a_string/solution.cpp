class Solution {
public:
    int ch[128]={}, ans = 0;
    int countVowelSubstrings(string word) {
        
        
        for (int i=0 ,j=0,k=0; i<word.size(); i++){
            if (isvowel(word[i])){
                ch[word[i]]+=1;
                for (; allvowel(); k++)
                    ch[word[k]]-=1;              
                ans +=  k - j;
            }
            else
                k=j=i+1,clear();
        }
        return ans;
    }
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int allvowel(){
        return (ch['a']&&ch['e']&&ch['i']&&ch['o']&&ch['u']);
    }
    void clear(){
        ch['a']=ch['e'] =ch['i'] =ch['o'] =ch['u'] = 0;
    }
};