class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int digit[10]={};
        int len=0;
        while (N){
            digit[N%10]++;
            N/=10;
            len++;
        }
        int lower_bound=0,upper_bound=0;
        for (int i=0; i<10; i++){
            int j = digit[i];
            while(j--){
                lower_bound =lower_bound*10+i;
            }
        }
        for (int i=9; i>=0; i--){
            int j = digit[i];
            while(j--){
                upper_bound =upper_bound*10+i;
            }
        }  
        int n=1;
        
        for (int i=1; i< 31; i++,n<<=1){
            if (lower_bound <=n && upper_bound>=n){
                int digit2[10]={0};
                int num=n;
                
                while(num){
                    digit2[num%10]++;
                    num/=10;
                }
                int i1=0;
                for (i1=0;  i1<10; i1++){
                    if(digit[i1]!= digit2[i1]) break;
                }
                if(i1==10) return true;
            }
        }
        return false;
    }
};