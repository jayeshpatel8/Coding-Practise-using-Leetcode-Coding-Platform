

bool isMatch(char * s, char * p){

    //"aaa"
    //"a*b*a*c*a"
    int sl = strlen(s), pl= strlen(p);
   
    int match[sl+1][pl+1];
    memset(match,0,sizeof match);
    match[sl][pl]=true;
    
    for (int i=sl; i>=0; i--)
        for (int j=pl-1; j>=0; j--)
        {
            int m = i< sl && (s[i]==p[j] || p[j]=='.');
            if ( j+1<pl && p[j+1]=='*'){ 
                    match[i][j]= match[i][j+2]|| m && match[i+1][j];
            }
            else 
                match[i][j]= m && match[i+1][j+1];
        }
    return match[0][0];
    //if (*p =='\0') return (*s=='\0');
    #if 0
    int match=(*s != '\0'  && (s[0]==p[0] || p[0]=='.')) ;
        
    if (p[1]!='\0' && p[1]=='*')
            return (isMatch(s, &p[2]) ||
                     (match && isMatch(&s[1], p)) );
    else
        return (match && isMatch(&s[1], &p[1]));
    #endif
}

