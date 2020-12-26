class Solution {
public:
   int n;
    string maximumBinaryString(string bi) {
        n=bi.length();
        int i=0;
        int zeros=0,firstone=0;
        int j=0;
        for (; j<n && (bi[j]=='1'); j++)  firstone++;
        for (; j<n; j++) if (bi[j]=='0') zeros++;
        if (zeros == 0) return bi;
        string s(n,'1');
        s[firstone + zeros-1]='0';
        return s;
        while (i+1<n && zeros> 1){
            string s = bi.substr(i,2);
            if (s == "00"){
                bi[i]='1';bi[i+1]='0'; i+=1; zeros--;
            }
            else if (s == "01") // 01000->00100->11101  01110->10111   01010 -> 10110 -> 11011
            {
                
                //bi[i]='1';bi[i+1]='1';
                int k = zeros-1;
                while(k>0){
                    
                    bi[i++]='1';k--;
                }
                bi[i++]='0';
                
                while (i<n)  bi[i++]='1';
                 return bi;

            }
            else if (s=="10") i++;
            else i+=2;
        }
        return bi;
    }
};