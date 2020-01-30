
int countAndSay_(char * r,char *s, int n){
    if(n==1) {r[0]='1';return 1;}
    
    int k = countAndSay_(r,s,n-1);
    int c=1,j=0, i=1;
    for (; i<k; i++){
        if (r[i] == r[i-1]) {c++;continue;}
        else
        {
            s[j+1]=r[i-1];
            s[j]='0'+c; j+=2;            
            c=1;
        }
    }
        s[j+1]=r[i-1];
    s[j++]='0'+c;
    j++;
    memcpy(r,s,j);
    return j;
}
char * countAndSay(int n){

    char * r = (char *) malloc(1024*400);
    
    r[countAndSay_(r,&r[1024*200], n)]='\0';
    return r;
}

