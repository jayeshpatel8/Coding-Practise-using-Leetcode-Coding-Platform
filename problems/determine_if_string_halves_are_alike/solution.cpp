class Solution {
public:
    bool halvesAreAlike(string s) {
        int n =s.length();
        int i=0,j=n-1,c=0;
        unordered_set<char> m={'a','e','i','o','u','A','E','I','O','U'};
        
        n=n/2;
         while (i<n ){
             if (m.find(s[i++])!=m.end()) c++;
             if (m.find(s[j--])!=m.end()) c--;
         
         }
        return c==0;        
    }
};