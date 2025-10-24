class Solution {
public:
    int nextBeautifulNumber(int n) {
         while(1){
             if (valid(++n))
                 return n;
         }   
         return 0;
    }
    bool valid(int n){
        int freq[10]={};
        while(n > 0)
            freq[n%10]++, n /=10;
        for (int i=0; i<=9; i++)
            if (freq[i] && i != freq[i]) return false;
        return true;
    }
};
