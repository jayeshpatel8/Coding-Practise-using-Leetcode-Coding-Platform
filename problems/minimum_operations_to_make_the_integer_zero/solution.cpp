class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
         long long n= num1;
        for (int cnt = 1; cnt <=60 && n > 0; cnt++){
            n -=num2;
            if ( __builtin_popcountll(n) <= cnt && n >= cnt) return cnt;
        }
        return -1;
    }
};