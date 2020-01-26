

int strStr(char * haystack, char * needle){
        if(needle && !needle[0]) {
        return 0;
    }
    int hlen = strlen(haystack), nlen = strlen(needle);
    if(hlen < nlen) {
        return -1;
    }
    
    int j=0;
    while(haystack[j])
    {
        
        if (haystack[j] ==  needle[0]){ 
            int i=1;
            if(j+nlen-1<=hlen )while( needle[i]!='\0' && haystack[j+i] == needle[i]){ i++;}
            if (needle[i]=='\0') return j;j++;
            }
        else
           j++; 
    }
    return -1;
}

