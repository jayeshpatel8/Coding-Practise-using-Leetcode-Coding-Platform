

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char * letters[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void combineStr(char *digits,int start,int end,char * returnString,char **combination,int* index,char *buff)
{
    if(start < end)
    {
        int len = strlen(letters[digits[start]-'0']);
        for(int i =0; i<len ;i++){
            returnString[start]=letters[digits[start]-'0'][i];
            combineStr(digits,start+1,end,returnString,combination,index,buff);
        }
    }
    else
    {
        combination[*index]=&buff[*index*(end+1)];
        returnString[end]='\0';
        strcpy(combination[*index],returnString);
        (*index)++;
    }
}
char ** letterCombinations(char * digits, int* returnSize){

    int returnStringLen=0, noOfString=1;
    for(int i=0; digits[i]!=0;i++)
    {
        if (digits[i] >='2' || digits[i] <= '9')
        {
            noOfString *=strlen(letters[digits[i]-'0']);
            returnStringLen++;
        }
    }
    *returnSize=0;
    if (!returnStringLen) return 0;
    char * returnString = (char * )malloc(1+returnStringLen);
    char ** combination=(char**)malloc(sizeof(char*)*noOfString);
    char * buff = (char *) malloc (noOfString*(returnStringLen+1));
    int  index=0;
    
    combineStr(digits,0,strlen(digits),returnString,combination,&index,buff);
    *returnSize=index;
    return combination;
}