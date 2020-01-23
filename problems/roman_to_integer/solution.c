

int romanToInt(char * s){

    int sum=0,i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='I')
            sum+=1;
        else if (s[i]=='V')
        {
            sum+=5;
            if(i>0 && s[i-1]=='I')
                sum-=2;
        }
        else if (s[i]=='X')
        {
            sum+=10;
            if(i>0 && s[i-1]=='I')
                sum-=2;
        }        
        else if (s[i]=='L')
        {
            sum+=50;
            if(i>0 && s[i-1]=='X')
                sum-=20;
        }        
        else if (s[i]=='C')
        {
            sum+=100;
            if(i>0 && s[i-1]=='X')
                sum-=20;
        }        
        else if (s[i]=='D')
        {
            sum+=500;
            if(i>0 && s[i-1]=='C')
                sum-=200;
        }        
        else if (s[i]=='M')
        {
            sum+=1000;
            if(i>0 && s[i-1]=='C')
                sum-=200;
        }  
        i++;
    }
    return sum;
}

