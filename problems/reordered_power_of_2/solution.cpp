class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int num = 1, len=0;
        vector<int> dig(10),dig2(10);
        while (n){
            dig[(n%10)]++;
            n/=10;
            ++len;
        }
        int l=1;
        dig2[1]++;

        while (l<= len){
            if (l == len){
                if (dig2 == dig) return true;
            }
            num <<=1;
            vector<int> d(10);
            n=num;
            l=0;
            while (n){
                d[n%10]++;
                n/=10;
                ++l;
            }
            dig2=d;
        }
        return false ;
    }
};