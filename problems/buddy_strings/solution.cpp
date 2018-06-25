class Solution {
public:
    bool buddyStrings(string A, string B) {
        size_t repeat=false,same=0,al = A.length(),bl=B.length();
        int f=-1;
        
        if ( (bl!= al) || !al)
            return false;
        char a[26];
        memset(a,0x0,26);
        
        while(al--)
        {
            if(A[al]!=B[al])
            {
                if(same <2){
                    if(f ==-1)
                        f=al;
                    else if (bl!=2){
                        if((A[f] != B[al]) || (A[al]!=B[f])) 
                            return false;
                    }
                    else if ((A[f] == B[al]) && (A[al]==B[f]) )
                        return true;
                    else 
                        return false;
                        
                    same++;
                    
                }
                else
                    return false;
            }
    
            a[A[al]-'a']++;
        }

        if (same ==1)
            return false;

        for(size_t c=0;c<26;c++)
        {
             if(a[c]>1)
                 return true;          
        }
        return false;
    }
};