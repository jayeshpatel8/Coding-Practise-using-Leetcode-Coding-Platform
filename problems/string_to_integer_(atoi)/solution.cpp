class Solution {
public:
    int myAtoi(string s) {
     int i=0,len=s.size();
     
     while(i < len && (s[i]==' '))
     {
         i++;
     }
     int sign=1;
    if (i < len )
    {
      if(s[i]=='-'){
          sign=-1;i++;}
      else if (s[i]=='+')
          i++;
    }
        int sum=0;
            if ((i < len && isdigit(s[i]))&& sign ==-1)
            {
                sum = sum * 10 + s[i]-'0';
                sum=~sum + 1 ;
                i++;
            }
        while (i < len && isdigit(s[i]))
        {
            if (sign ==-1)
            {
              if (sum < INT_MIN/10 || (sum == INT_MIN/10 && (s[i]-'0')>8))
                  return INT_MIN;

              sum = sum * 10 - (s[i]-'0');  
            }
            else
            {
              if (sum > INT_MAX/10 || (sum == INT_MAX/10 && (s[i]-'0')>7))
                  return INT_MAX;
              sum = sum * 10 + (s[i]-'0');                  
            }
            i++;
        }
        return (sum);
    }
};