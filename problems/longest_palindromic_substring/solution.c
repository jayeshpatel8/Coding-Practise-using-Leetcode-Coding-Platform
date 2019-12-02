

char * longestPalindrome(char * s){

    if (!s || *s=='\0')
        return s;
    int l = strlen(s),max_len=1,start=0;
    
    for (int i =0; i < l; i++)
    {
        int low =i-1, high = i;
        
        while (low>=0 && high < l && s[low] == s[high])
        {
            if (high -low +1 > max_len)
            {
                max_len = high -low +1;
                start = low;
            }
            low--,high++;
        }
        
        low =i-1, high = i +1;
        while (low>=0 && high < l && s[low] == s[high])
        {
            if (high -low +1 > max_len)
            {
                max_len = high -low +1;
                start = low;
            }
            low--,high++;
        }        
    }
    if (max_len)
        s[start + max_len ]=0;
    return &s[start ];
}

