class Solution {
public:
    bool halvesAreAlike(string s) {
     
        int vowel=0;
        
        for (int i=0,j=s.size()-1; i<j; i++,j--){
            vowel += isVowel(s[i]);
            vowel -= isVowel(s[j]);
        }
        return vowel==0;
    }
    bool isVowel(int c){
        if (c < 'a') return (c =='A' || c =='E' || c =='I' || c =='O' || c =='U');
        return (c =='a' || c =='e' || c =='i' || c =='o' || c =='u');
    }
};