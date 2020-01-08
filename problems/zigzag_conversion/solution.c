

char * convert(char * s, int numRows){
    
    int k=0,len=strlen(s);
    char * out=(char *) malloc (len+1);
        int next=numRows*2-2;
    if (len <3 || next==0)
        return s;
        
    for (int i=0; i < numRows && i < len; i++)
    {
        
        for (int j=i; j<len;j+=next)
        {
            out[k++]=s[j];
            if (i !=0 && i != numRows-1 && (j+next-2*i) <len)
                out[k++]=s[j+next-2*i];
        }
    }
     (out[k]='\0');
    
    return out;
    
}