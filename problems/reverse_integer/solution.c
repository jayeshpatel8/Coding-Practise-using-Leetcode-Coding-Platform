

int reverse(int x){
int sign = x & 0x80000000;
int r_num=0;

 while(x)
 {
     int rem = (x % 10);
     if( (r_num > INT_MAX/10) || ((r_num == INT_MAX/10) && (rem > 7) )  || (r_num < INT_MIN/10) || ((r_num == INT_MIN/10) && ( rem< -8) )){

             return 0;
     }
     
     r_num = r_num * 10 + rem;
     x /=10;

 }

 return r_num;
}

