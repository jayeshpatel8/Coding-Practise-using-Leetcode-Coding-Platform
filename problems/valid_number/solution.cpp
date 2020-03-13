class Solution {
public:
    bool isNumber(string s) {
        int n =s.size(),i=0;
        int dot=0, dig=0;

        while(i<n && s[i] == ' ') i++;
        
        if (i<n && (s[i]=='+'||s[i]=='-')) i++;
        
        if (i<n && (s[i]=='.')) dot++,i++;
        
        while(i<n && (s[i] >='0' && s[i]<= '9' )) dig=1,i++;        
        
        if (i<n && dig && !dot && (s[i]=='.')) i++;        
        
        while(i<n && (s[i] >='0' && s[i]<= '9' )) dig=1,i++;        
  
        if (i<n && dig && (s[i]=='e')){ 
            i++;
            if (i<n && (s[i]=='+'||s[i]=='-')) i++;      
            dig=0;
        }
        
        while(i<n && (s[i] >='0' && s[i]<= '9' )) dig=1,i++;


        while(i<n && s[i]==' ') i++;        
        return ((i==n)&&dig );
    }
};
//-.1e-24. 