

int divide(int dividend, int divisor){

        if (divisor == 1)
        return dividend;
    if (divisor == -1) {
        if (dividend == INT_MIN)
            return INT_MAX;
        else
            return -dividend;
    }
    
    int minus = (divisor < 0?1:0) ^ (dividend<0?1:0);

     unsigned int res=0;
    unsigned int dnd,div;
    if (dividend == INT_MIN){
        dnd = abs(dividend+1);
        dnd +=1;}
    else
        dnd = abs(dividend);
    if (divisor == INT_MIN){
        div = abs(divisor+1);
        div +=1;}
    else
        div = abs(divisor);       

        if (divisor == 1){
            res = dnd;
                int r=res;

        if (minus)
          r =(unsigned int)~r+1;

        return r;
    }
    else   
        while(dnd >= div ){
            res +=1;
            dnd -=div;        
        }
    if (res>INT_MAX)
        res=INT_MAX;
    int r=res;

    if (minus)
      r =~r+1;

    return r;
    
}

