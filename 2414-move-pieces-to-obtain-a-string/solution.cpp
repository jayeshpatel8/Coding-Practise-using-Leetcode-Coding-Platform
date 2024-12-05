class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0;
         int N=s.size();
        while (i<N || j<N){
            
            while (i<N && s[i] == '_') i++;

            while (j<N && t[j] == '_') j++;
            
            if(( i==N) || (j==N)) break ;

            if (s[i] != t[j] ) return false;
            if (s[i]=='L' && i<j )return false;
            if (s[i]=='R' && i>j)return false;
            i++,j++;
        }
       
        
        return (i==N) && (j==N);
    }
};
