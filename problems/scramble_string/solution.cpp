
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1,0,s1.size(),s2,0,s2.size());
    }
    private:
    bool isScramble(string& s1,int start1,int len1, string& s2, int start2, int len2) {
        
        if (len1!=len2) return false;
        
        vector<char> cnt(26,0);
        bool match = true;
        
        
        for (int i=0;  i<len1; i++){
            if (s1[start1+i]!=s2[start2+i]) match=false;
            cnt[s1[start1+i]-'a']++,cnt[s2[start2+i]-'a']--;
        }
        if (match) return true;
        for (auto &i : cnt)
            if (i)return false;
        
        for (int i=1; i< len1; i++){
           
            if (isScramble(s1,start1,i,s2,start2,i) && isScramble(s1,start1+i,len1-i, s2,start2+i,len2-i)) return true;
            if (isScramble(s1,start1,i,s2,start2+len2-i,i) && isScramble(s1,start1+i,len1-i, s2,start2,len2-i)) return true;            
        }
        return false;
    }    
};