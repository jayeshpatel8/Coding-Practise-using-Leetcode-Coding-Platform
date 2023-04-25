class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 =  __builtin_popcount(num2);
        int cnt1 =  __builtin_popcount(num1);
        cnt1 -=cnt2;
        if (cnt1== 0) return num1;
        
        if (cnt1> 0){
            for (; cnt1>0; ){
                num1 &= (num1-1);
                cnt1--;
            }
        }
        else{
            for (int i=0; cnt1<0; i++){
                if ((num1 & (1u<<i)) == 0){
                    num1 |= (1u<<i);
                    cnt1++;
                }
            }
        }
        return num1;
    }
};