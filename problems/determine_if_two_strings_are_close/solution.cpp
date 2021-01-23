class Solution {
public:
     bool closeStrings(string word1, string word2) {
         if (word1.size() != word2.size()) return false;
         int freq1[26]={};
         int freq2[26]={};
         for (auto c  : word1) {freq1[c-'a']++;}
         for (auto c  : word2) freq2[c-'a']++;
        //"cabbba"
        //"abbccc"
         for (int i=0; i<26; i++)
             if (!freq2[i] && !freq1[i]==0) return false;
                    
         sort(freq1, freq1+26);
         sort(freq2, freq2+26);
         
         for (int i=0; i<26; i++)
             if (freq1[i] != freq2[i]) return false; 
         
         return true;

    }  
};