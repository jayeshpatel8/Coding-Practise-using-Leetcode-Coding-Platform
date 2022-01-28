class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int freq[3]={};
        for (int i=0,j=0,f=0,N=s.size(); i<N ;i++ ){
            freq[s[i]-'a']++;
            f = (freq[0]!=0) && (freq[1]!=0) && (freq[2]!=0) ; 
            
            while (f){                
                freq[s[j]-'a']--;
                f = freq[s[j++]-'a'] ;                 
                ans += N-i;    
            }            
        }
        return ans;
    }
};