class Solution {
public:
    int getLucky(string s, int k) {
        uint64_t num = 0;
        for ( auto c : s){
            if (c <'j') num += c - 'a' + 1;
            else if (c <'t') num += c -'j' + 1;
            else num += c - 't' + 2;
        }
        while (--k){
            uint64_t digit_sum = 0;
            while(num){
                digit_sum +=num%10;                
                num/=10;
            }
            num = digit_sum ;
        }
        return num;
    }
};