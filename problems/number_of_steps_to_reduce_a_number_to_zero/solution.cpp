class Solution {
public:
    int numberOfSteps (int num) {
        int cnt=0;
        while (num & (num-1)) {
            cnt++;
            num &= num-1;
        }
        while (num){
            cnt++; num>>=1;
        }
        return cnt;
    }    
};