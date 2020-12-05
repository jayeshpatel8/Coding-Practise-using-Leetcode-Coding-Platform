class Solution {
public:

    string reverseWords(string s) {
        int n = s.length();
        // remove the space and reverse each word
        int start=0,j=-1,i=0;
        for (; i<n; i++){
            if (s[i]==' ' && j==-1 || s[i] != ' ' && j!=-1) continue;
            if (j==-1) j=i;
            else{
                
                //rev word
                int st=j, en=i-1;
                while(st<en){ char c = s[st]; s[st++]=s[en];s[en--]=c; }        
                
                if (start!=0) s[start++]=' ';
                //copy to start
                int len=i-j;
                while(len--) s[start++]=s[j++];
                j=-1;
            }
        }
        
        if (j!=-1){
                int st=j, en=i-1;
                while(st<en){ char c = s[st]; s[st++]=s[en];s[en--]=c; }        
                if (start!=0) s[start++]=' ';
                //copy to start
                int len=i-j;
                while(len--) s[start++]=s[j++];
        }
        
        // str rev
        i=0, j=start-1;
        while (i<j){
            char c  = s[j];
            s[j--]=s[i];
            s[i++]=c;
        }
        s.resize(start);
        return s;
    }
};