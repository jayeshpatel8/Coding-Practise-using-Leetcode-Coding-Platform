

char * intToRoman(int num){

    char* str= (char *)malloc(4*4);
    int i=0;
   // while(num)
    {
        if (num>=1000 )
        {            
            while(num/1000){
                str[i++]='M';
                num = num - 1000;
            }
        }
         if (num >= 900)
        {
                str[i++]='C';str[i++]='M';num = num - 900;
        }            
         if (num >=500)
        {
            
            while(num/500){
                str[i++]='D';
            num = num - 500;}
        }
         if (num >= 400)
        {
            str[i++]='C';str[i++]='D';num = num - 400;
        }     
         if (num >=100)
        {
           // int cnt = ;
            while(num/100){
                str[i++]='C';
            num = num - 100;}
        }
         if (num >= 90)
        {
            str[i++]='X';str[i++]='C';num = num - 90;
        }    
         if (num >=50)
        {
            
            while(num/50){
                str[i++]='L';
            num = num - 50;}
        }
         if (num >= 40)
        {
            str[i++]='X';str[i++]='L';num = num - 40;
        }
         if (num >=10)
        {
           
            while(num/10){
                str[i++]='X';
            num = num - 10;}
        }
         if (num >= 9)
        {
            str[i++]='I';str[i++]='X';num = num - 9;
        }    
         if (num >=5)
        {
           // int cnt = num/5;
            while(num/5){
                str[i++]='V';
            num = num -5;}
        }
         if (num >= 4)
        {
            str[i++]='I';str[i++]='V';num = num - 4;
        } 
         if (num >=1)
        {
            
            while(num--)
                str[i++]='I';
      
        }        
    }
    str[i]='\0';
    return &str[0];
}

