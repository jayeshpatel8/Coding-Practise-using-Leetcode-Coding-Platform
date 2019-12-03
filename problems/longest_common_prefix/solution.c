
char e_str[]="";
char * longestCommonPrefix(char ** strs, int strsSize){

    if (strsSize==0|| strs== 0 || *strs==0  )
        return e_str;
    int max=strlen(strs[0]);
    for (int j=1; j <strsSize; j++)
    {
        int len=strlen(strs[j]), k=0;
        for (int i=0; i < max && i < len && (strs[0][i] == strs[j][i]); i++)
                k++;

        if (max > k)
            max=k;
    }
    if(max >0){
        strs[0][max]=0;
        return strs[0];
    }
    else
       return e_str; 
}

